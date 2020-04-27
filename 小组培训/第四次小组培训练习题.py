from lxml import etree
import requests
import pymysql
# import pandas as pd
# import xlwt
movies_dict={
    'rank':[],
    'title':[],
    'director':[],
    'score':[],
    'about':[],
    'more_url':[],
    'thumbnail':[],
    'type':[]
}
def analize_url(url):
    headers={
        'User-Agent':'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.130 Safari/537.36',
        'Referer':'https://movie.douban.com/chart'
    }
    response=requests.get(url,headers=headers)
    text=response.text
    html=etree.HTML(text)
    return html

def get_data(html):
    global movies_dict
    ol=html.xpath("//ol[@class='grid_view']")[0]
    lis=ol.xpath("./li")
    for li in lis:
        movies_dict['rank'].append(int(li.xpath(".//em/text()")[0]))
        movies_dict['title'].append(li.xpath(".//span[@class='title']/text()")[0])
        movies_dict['score'].append(float(li.xpath(".//span[@property='v:average']/text()")[0]))
        movies_dict['thumbnail'].append(li.xpath(".//img/@src")[0])
        movies_dict['more_url'].append(li.xpath(".//a[1]/@href")[0])
        movies_dict['director'].append(li.xpath(".//p/text()")[0].replace(" ","").replace("\n","").replace("\xa0\xa0\xa0"," "))
        movies_dict['about'].append(li.xpath(".//span[@class='inq']/text()")[0])
        movies_dict['type'].append(li.xpath(".//p/text()")[1].replace("\n                        ","").replace("\xa0/\xa0"," ").replace("    ",""))

def insert_data_to_mysql():
    conn = pymysql.connect(host='localhost', user='root', password='asdfghjkl12', database='pymysql_demo', port=3306)
    cursor = conn.cursor()
    for i in range(100):
        sql = """
        insert into user(id,标题,评分,类型,导演,图片网址,详情) values(%s,%s,%s,%s,%s,%s,%s)"""
        cursor.execute(sql,(movies_dict["rank"][i], movies_dict["title"][i], movies_dict["score"][i], movies_dict["type"][i], movies_dict["director"][i], movies_dict["thumbnail"][i], movies_dict["about"][i]))
        conn.commit()
    conn.close()

# def export_excel(export):
#    pf = pd.DataFrame(export)
#    file_path = pd.ExcelWriter('film_top100.xlsx')
#    pf.fillna(' ',inplace = True)
#    pf.to_excel(file_path,encoding = 'utf-8',index = False)
#    file_path.save()

if __name__ == '__main__':
    for i in range(4):
        url='https://movie.douban.com/top250?start='+str(i*25)+'&filter='
        html=analize_url(url)
        get_data(html)
    insert_data_to_mysql()

