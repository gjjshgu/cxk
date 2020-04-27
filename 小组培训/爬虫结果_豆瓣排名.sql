/*
 Navicat Premium Data Transfer

 Source Server         : cxk
 Source Server Type    : MySQL
 Source Server Version : 80019
 Source Host           : localhost:3306
 Source Schema         : pymysql_demo

 Target Server Type    : MySQL
 Target Server Version : 80019
 File Encoding         : 65001

 Date: 27/04/2020 22:14:28
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for user
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user` (
  `排名` int NOT NULL AUTO_INCREMENT,
  `标题` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
  `评分` float DEFAULT NULL,
  `导演` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
  `类型` varchar(255) DEFAULT NULL,
  `图片网址` varchar(255) DEFAULT NULL,
  `详情` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`排名`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=101 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of user
-- ----------------------------
BEGIN;
INSERT INTO `user` VALUES (1, '肖申克的救赎', 9.7, '导演:弗兰克·德拉邦特FrankDarabont 主演:蒂姆·罗宾斯TimRobbins/...', '1994 美国 犯罪 剧情', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p480747492.jpg', '希望让人自由。');
INSERT INTO `user` VALUES (2, '霸王别姬', 9.6, '导演:陈凯歌KaigeChen 主演:张国荣LeslieCheung/张丰毅FengyiZha...', '1993 中国大陆 中国香港 剧情 爱情 同性', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p2561716440.jpg', '风华绝代。');
INSERT INTO `user` VALUES (3, '阿甘正传', 9.5, '导演:罗伯特·泽米吉斯RobertZemeckis 主演:汤姆·汉克斯TomHanks/...', '1994 美国 剧情 爱情', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p1484728154.jpg', '一部美国近现代史。');
INSERT INTO `user` VALUES (4, '这个杀手不太冷', 9.4, '导演:吕克·贝松LucBesson 主演:让·雷诺JeanReno/娜塔莉·波特曼...', '1994 法国 剧情 动作 犯罪', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p511118051.jpg', '怪蜀黍和小萝莉不得不说的故事。');
INSERT INTO `user` VALUES (5, '美丽人生', 9.5, '导演:罗伯托·贝尼尼RobertoBenigni 主演:罗伯托·贝尼尼RobertoBeni...', '1997 意大利 剧情 喜剧 爱情 战争', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p2578474613.jpg', '最美的谎言。');
INSERT INTO `user` VALUES (6, '泰坦尼克号', 9.4, '导演:詹姆斯·卡梅隆JamesCameron 主演:莱昂纳多·迪卡普里奥Leonardo...', '1997 美国 剧情 爱情 灾难', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p457760035.jpg', '失去的才是永恒的。 ');
INSERT INTO `user` VALUES (7, '千与千寻', 9.3, '导演:宫崎骏HayaoMiyazaki 主演:柊瑠美RumiHîragi/入野自由Miy...', '2001 日本 剧情 动画 奇幻', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p2557573348.jpg', '最好的宫崎骏，最好的久石让。 ');
INSERT INTO `user` VALUES (8, '辛德勒的名单', 9.5, '导演:史蒂文·斯皮尔伯格StevenSpielberg 主演:连姆·尼森LiamNeeson...', '1993 美国 剧情 历史 战争', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p492406163.jpg', '拯救一个人，就是拯救整个世界。');
INSERT INTO `user` VALUES (9, '盗梦空间', 9.3, '导演:克里斯托弗·诺兰ChristopherNolan 主演:莱昂纳多·迪卡普里奥Le...', '2010 美国 英国 剧情 科幻 悬疑 冒险', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p513344864.jpg', '诺兰给了我们一场无法盗取的梦。');
INSERT INTO `user` VALUES (10, '忠犬八公的故事', 9.4, '导演:莱塞·霍尔斯道姆LasseHallström 主演:理查·基尔RichardGer...', '2009 美国 英国 剧情', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p524964016.jpg', '永远都不能忘记你所爱的人。');
INSERT INTO `user` VALUES (11, '海上钢琴师', 9.3, '导演:朱塞佩·托纳多雷GiuseppeTornatore 主演:蒂姆·罗斯TimRoth/...', '1998 意大利 剧情 音乐', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p2574551676.jpg', '每个人都要走一条自己坚定了的路，就算是粉身碎骨。 ');
INSERT INTO `user` VALUES (12, '机器人总动员', 9.3, '导演:安德鲁·斯坦顿AndrewStanton 主演:本·贝尔特BenBurtt/艾丽...', '2008 美国 科幻 动画 冒险', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p1461851991.jpg', '小瓦力，大人生。');
INSERT INTO `user` VALUES (13, '三傻大闹宝莱坞', 9.2, '导演:拉库马·希拉尼RajkumarHirani 主演:阿米尔·汗AamirKhan/卡...', '2009 印度 剧情 喜剧 爱情 歌舞', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p579729551.jpg', '英俊版憨豆，高情商版谢耳朵。');
INSERT INTO `user` VALUES (14, '楚门的世界', 9.3, '导演:彼得·威尔PeterWeir 主演:金·凯瑞JimCarrey/劳拉·琳妮Lau...', '1998 美国 剧情 科幻', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p479682972.jpg', '如果再也不能见到你，祝你早安，午安，晚安。');
INSERT INTO `user` VALUES (15, '放牛班的春天', 9.3, '导演:克里斯托夫·巴拉蒂ChristopheBarratier 主演:热拉尔·朱尼奥Gé...', '2004 法国 瑞士 德国 剧情 音乐', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p1910824951.jpg', '天籁一般的童声，是最接近上帝的存在。 ');
INSERT INTO `user` VALUES (16, '星际穿越', 9.3, '导演:克里斯托弗·诺兰ChristopherNolan 主演:马修·麦康纳MatthewMc...', '2014 美国 英国 加拿大 冰岛 剧情 科幻 冒险', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p2206088801.jpg', '爱是一种力量，让我们超越时空感知它的存在。');
INSERT INTO `user` VALUES (17, '大话西游之大圣娶亲', 9.2, '导演:刘镇伟JeffreyLau 主演:周星驰StephenChow/吴孟达ManTatNg...', '1995 中国香港 中国大陆 喜剧 爱情 奇幻 古装', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p2455050536.jpg', '一生所爱。');
INSERT INTO `user` VALUES (18, '熔炉', 9.3, '导演:黄东赫Dong-hyukHwang 主演:孔侑YooGong/郑有美Yu-miJeong...', '2011 韩国 剧情', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p1363250216.jpg', '我们一路奋战不是为了改变世界，而是为了不让世界改变我们。');
INSERT INTO `user` VALUES (19, '疯狂动物城', 9.2, '导演:拜伦·霍华德ByronHoward/瑞奇·摩尔RichMoore 主演:金妮弗·...', '2016 美国 喜剧 动画 冒险', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p2315672647.jpg', '迪士尼给我们营造的乌托邦就是这样，永远善良勇敢，永远出乎意料。');
INSERT INTO `user` VALUES (20, '无间道', 9.2, '导演:刘伟强/麦兆辉 主演:刘德华/梁朝伟/黄秋生', '2002 中国香港 剧情 犯罪 悬疑', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p2564556863.jpg', '香港电影史上永不过时的杰作。');
INSERT INTO `user` VALUES (21, '龙猫', 9.2, '导演:宫崎骏HayaoMiyazaki 主演:日高法子NorikoHidaka/坂本千夏Ch...', '1988 日本 动画 奇幻 冒险', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p2540924496.jpg', '人人心中都有个龙猫，童年就永远不会消失。');
INSERT INTO `user` VALUES (22, '教父', 9.3, '导演:弗朗西斯·福特·科波拉FrancisFordCoppola 主演:马龙·白兰度M...', '1972 美国 剧情 犯罪', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p616779645.jpg', '千万不要记恨你的对手，这样会让你失去理智。');
INSERT INTO `user` VALUES (23, '当幸福来敲门', 9.1, '导演:加布里尔·穆奇诺GabrieleMuccino 主演:威尔·史密斯WillSmith...', '2006 美国 剧情 传记 家庭', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p1312700628.jpg', '平民励志片。 ');
INSERT INTO `user` VALUES (24, '怦然心动', 9.1, '导演:罗伯·莱纳RobReiner 主演:玛德琳·卡罗尔MadelineCarroll/卡...', '2010 美国 剧情 喜剧 爱情', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p501177648.jpg', '真正的幸福是来自内心深处。');
INSERT INTO `user` VALUES (25, '触不可及', 9.2, '导演:奥利维·那卡什OlivierNakache/艾力克·托兰达EricToledano 主...', '2011 法国 剧情 喜剧', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p1454261925.jpg', '满满温情的高雅喜剧。');
INSERT INTO `user` VALUES (26, '蝙蝠侠：黑暗骑士', 9.2, '导演:克里斯托弗·诺兰ChristopherNolan 主演:克里斯蒂安·贝尔Christ...', '2008 美国 英国 剧情 动作 科幻 犯罪 惊悚', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p462657443.jpg', '无尽的黑暗。');
INSERT INTO `user` VALUES (27, '控方证人', 9.6, '导演:比利·怀尔德BillyWilder 主演:泰隆·鲍华TyronePower/玛琳·...', '1957 美国 剧情 犯罪 悬疑', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p1505392928.jpg', '比利·怀德满分作品。');
INSERT INTO `user` VALUES (28, '活着', 9.2, '导演:张艺谋YimouZhang 主演:葛优YouGe/巩俐LiGong/姜武WuJiang', '1994 中国大陆 中国香港 剧情 历史 家庭', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p2513253791.jpg', '张艺谋最好的电影。');
INSERT INTO `user` VALUES (29, '乱世佳人', 9.3, '导演:维克多·弗莱明VictorFleming/乔治·库克GeorgeCukor 主演:费...', '1939 美国 剧情 历史 爱情 战争', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p1963126880.jpg', 'Tomorrow is another day.');
INSERT INTO `user` VALUES (30, '末代皇帝', 9.2, '导演:贝纳尔多·贝托鲁奇BernardoBertolucci 主演:尊龙JohnLone/陈...', '1987 英国 意大利 中国大陆 法国 剧情 传记 历史', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p452089833.jpg', '“不要跟我比惨，我比你更惨”再适合这部电影不过了。');
INSERT INTO `user` VALUES (31, '摔跤吧！爸爸', 9, '导演:涅提·蒂瓦里NiteshTiwari 主演:阿米尔·汗AamirKhan/法缇玛...', '2016 印度 剧情 传记 运动 家庭', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p2457983084.jpg', '你不是在为你一个人战斗，你要让千千万万的女性看到女生并不是只能相夫教子。');
INSERT INTO `user` VALUES (32, '寻梦环游记', 9.1, '导演:李·昂克里奇LeeUnkrich/阿德里安·莫利纳AdrianMolina 主演:...', '2017 美国 喜剧 动画 奇幻 音乐', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p2503997609.jpg', '死亡不是真的逝去，遗忘才是永恒的消亡。');
INSERT INTO `user` VALUES (33, '少年派的奇幻漂流', 9.1, '导演:李安AngLee 主演:苏拉·沙玛SurajSharma/伊尔凡·可汗Irrfan...', '2012 美国 中国台湾 英国 加拿大 剧情 奇幻 冒险', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p1784592701.jpg', '瑰丽壮观、无人能及的冒险之旅。');
INSERT INTO `user` VALUES (34, '指环王3：王者无敌', 9.2, '导演:彼得·杰克逊PeterJackson 主演:维果·莫腾森ViggoMortensen/...', '2003 美国 新西兰 剧情 动作 奇幻 冒险', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p1910825503.jpg', '史诗的终章。');
INSERT INTO `user` VALUES (35, '飞屋环游记', 9, '导演:彼特·道格特PeteDocter/鲍勃·彼德森BobPeterson 主演:爱德...', '2009 美国 剧情 喜剧 动画 冒险', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p485887754.jpg', '最后那些最无聊的事情，才是最值得怀念的。 ');
INSERT INTO `user` VALUES (36, '十二怒汉', 9.4, '导演:SidneyLumet 主演:亨利·方达HenryFonda/马丁·鲍尔萨姆Marti...', '1957 美国 剧情', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p2173577632.jpg', '1957年的理想主义。 ');
INSERT INTO `user` VALUES (37, '鬼子来了', 9.2, '导演:姜文WenJiang 主演:姜文WenJiang/香川照之TeruyukiKagawa/...', '2000 中国大陆 剧情 历史 战争', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p2553104888.jpg', '对敌人的仁慈，就是对自己残忍。');
INSERT INTO `user` VALUES (38, '天空之城', 9.1, '导演:宫崎骏HayaoMiyazaki 主演:田中真弓MayumiTanaka/横泽启子Ke...', '1986 日本 动画 奇幻 冒险', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p1446261379.jpg', '对天空的追逐，永不停止。 ');
INSERT INTO `user` VALUES (39, '何以为家', 9.1, '导演:娜丁·拉巴基NadineLabaki 主演:扎因·拉费阿Zainal-Rafeea/...', '2018 黎巴嫩 法国 美国 剧情', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p2555295759.jpg', '凝视卑弱生命，用电影改变命运。');
INSERT INTO `user` VALUES (40, '大话西游之月光宝盒', 9, '导演:刘镇伟JeffreyLau 主演:周星驰StephenChow/吴孟达ManTatNg...', '1995 中国香港 中国大陆 喜剧 爱情 奇幻 古装', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p2561721372.jpg', '旷古烁今。');
INSERT INTO `user` VALUES (41, '哈尔的移动城堡', 9, '导演:宫崎骏HayaoMiyazaki 主演:倍赏千惠子ChiekoBaishô/木村拓...', '2004 日本 动画 奇幻 冒险', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p2174346180.jpg', '带着心爱的人在天空飞翔。');
INSERT INTO `user` VALUES (42, '天堂电影院', 9.2, '导演:朱塞佩·托纳多雷GiuseppeTornatore 主演:安东内拉·阿蒂利Anton...', '1988 意大利 法国 剧情 爱情', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p2559577569.jpg', '那些吻戏，那些青春，都在影院的黑暗里被泪水冲刷得无比清晰。');
INSERT INTO `user` VALUES (43, '素媛', 9.2, '导演:李濬益Jun-ikLee 主演:薛景求Kyung-guSol/严志媛Ji-wonUhm...', '2013 韩国 剧情', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p2118532944.jpg', '受过伤害的人总是笑得最开心，因为他们不愿意让身边的人承受一样的痛苦。');
INSERT INTO `user` VALUES (44, '罗马假日', 9, '导演:威廉·惠勒WilliamWyler 主演:奥黛丽·赫本AudreyHepburn/格...', '1953 美国 喜剧 剧情 爱情', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p2189265085.jpg', '爱情哪怕只有一天。');
INSERT INTO `user` VALUES (45, '闻香识女人', 9.1, '导演:马丁·布莱斯MartinBrest 主演:阿尔·帕西诺AlPacino/克里斯...', '1992 美国 剧情', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p2550757929.jpg', '史上最美的探戈。');
INSERT INTO `user` VALUES (46, '辩护人', 9.2, '导演:杨宇硕Woo-seokYang 主演:宋康昊Kang-hoSong/吴达洙Dal-suO...', '2013 韩国 剧情', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p2158166535.jpg', '电影的现实意义大过电影本身。');
INSERT INTO `user` VALUES (47, '搏击俱乐部', 9, '导演:大卫·芬奇DavidFincher 主演:爱德华·诺顿EdwardNorton/布拉...', '1999 美国 德国 剧情 动作 悬疑 惊悚', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p1910926158.jpg', '邪恶与平庸蛰伏于同一个母体，在特定的时间互相对峙。');
INSERT INTO `user` VALUES (48, '哈利·波特与魔法石', 9, '导演:ChrisColumbus 主演:DanielRadcliffe/EmmaWatson/RupertGrint', '2001 美国 英国 奇幻 冒险', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p804947166.jpg', '童话世界的开端。');
INSERT INTO `user` VALUES (49, '死亡诗社', 9.1, '导演:彼得·威尔PeterWeir 主演:罗宾·威廉姆斯RobinWilliams/罗伯...', '1989 美国 剧情', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p2575465690.jpg', '当一个死水般的体制内出现一个活跃的变数时，所有的腐臭都站在了光明的对面。');
INSERT INTO `user` VALUES (50, '窃听风暴', 9.1, '导演:弗洛里安·亨克尔·冯·多纳斯马尔克FlorianHenckelvonDonnersmarck  &n...', '2006 德国 剧情 悬疑', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p1808872109.jpg', '别样人生。');
INSERT INTO `user` VALUES (51, '教父2', 9.2, '导演:弗朗西斯·福特·科波拉FrancisFordCoppola 主演:阿尔·帕西诺A...', '1974 美国 剧情 犯罪', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p2194138787.jpg', '优雅的孤独。');
INSERT INTO `user` VALUES (52, '狮子王', 9, '导演:RogerAllers/罗伯·明可夫RobMinkoff 主演:乔纳森·泰勒·托马...', '1994 美国 动画 冒险 歌舞', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p2277799019.jpg', '动物版《哈姆雷特》。');
INSERT INTO `user` VALUES (53, '指环王2：双塔奇兵', 9.1, '导演:彼得·杰克逊PeterJackson 主演:伊利亚·伍德ElijahWood/西恩...', '2002 美国 新西兰 剧情 动作 奇幻 冒险', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p909265336.jpg', '承前启后的史诗篇章。');
INSERT INTO `user` VALUES (54, '我不是药神', 9, '导演:文牧野MuyeWen 主演:徐峥ZhengXu/王传君ChuanjunWang/周...', '2018 中国大陆 剧情 喜剧', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p2561305376.jpg', '对我们国家而言，这样的电影多一部是一部。');
INSERT INTO `user` VALUES (55, '大闹天宫', 9.3, '导演:万籁鸣LaimingWan/唐澄ChengTang 主演:邱岳峰YuefengQiu/...', '1961(中国大陆) / 1964(中国大陆) / 1978(中国大陆) / 2004(中国大陆) 中国大陆 动画 奇幻', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p2184505167.jpg', '经典之作，历久弥新。');
INSERT INTO `user` VALUES (56, '两杆大烟枪', 9.1, '导演:GuyRitchie 主演:JasonFlemyng/DexterFletcher/NickMoran', '1998 英国 剧情 喜剧 犯罪', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p792443418.jpg', '4个臭皮匠顶个诸葛亮，盖·里奇果然不是盖的。');
INSERT INTO `user` VALUES (57, '指环王1：魔戒再现', 9, '导演:彼得·杰克逊PeterJackson 主演:伊利亚·伍德ElijahWood/西恩...', '2001 新西兰 美国 剧情 动作 奇幻 冒险', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p1354436051.jpg', '传说的开始。');
INSERT INTO `user` VALUES (58, '飞越疯人院', 9.1, '导演:米洛斯·福尔曼MilošForman 主演:杰克·尼科尔森JackNichols...', '1975 美国 剧情', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p792238287.jpg', '自由万岁。');
INSERT INTO `user` VALUES (59, '美丽心灵', 9, '导演:朗·霍华德RonHoward 主演:罗素·克劳RussellCrowe/艾德·哈...', '2001 美国 传记 剧情', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p1665997400.jpg', '爱是一切逻辑和原由。');
INSERT INTO `user` VALUES (60, '饮食男女', 9.1, '导演:李安AngLee 主演:郎雄SihungLung/杨贵媚Kuei-MeiYang/吴...', '1994 中国台湾 美国 剧情 家庭', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p1910899751.jpg', '人生不能像做菜，把所有的料都准备好了才下锅。');
INSERT INTO `user` VALUES (61, 'V字仇杀队', 8.9, '导演:詹姆斯·麦克特格JamesMcTeigue 主演:娜塔莉·波特曼NataliePor...', '2005 美国 英国 德国 剧情 动作 科幻 惊悚', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p1465235231.jpg', '一张面具背后的理想与革命。');
INSERT INTO `user` VALUES (62, '黑客帝国', 9, '导演:安迪·沃卓斯基AndyWachowski/拉娜·沃卓斯基LanaWachowski 主...', '1999 美国 澳大利亚 动作 科幻', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p451926968.jpg', '视觉革命。');
INSERT INTO `user` VALUES (63, '猫鼠游戏', 9, '导演:史蒂文·斯皮尔伯格StevenSpielberg 主演:莱昂纳多·迪卡普里奥L...', '2002 美国 加拿大 传记 犯罪 剧情', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p453924541.jpg', '骗子大师和执著警探的你追我跑故事。 ');
INSERT INTO `user` VALUES (64, '钢琴家', 9.1, '导演:罗曼·波兰斯基RomanPolanski 主演:艾德里安·布洛迪AdrienBrod...', '2002 法国 德国 英国 波兰 剧情 传记 历史 战争 音乐', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p792376093.jpg', '音乐能化解仇恨。');
INSERT INTO `user` VALUES (65, '本杰明·巴顿奇事', 8.9, '导演:大卫·芬奇DavidFincher 主演:凯特·布兰切特CateBlanchett/...', '2008 美国 剧情 爱情 奇幻', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p2192535722.jpg', '在时间之河里感受溺水之苦。');
INSERT INTO `user` VALUES (66, '看不见的客人', 8.8, '导演:奥里奥尔·保罗OriolPaulo 主演:马里奥·卡萨斯MarioCasas/阿...', '2016 西班牙 剧情 犯罪 悬疑 惊悚', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p2498971355.jpg', '你以为你以为的就是你以为的。');
INSERT INTO `user` VALUES (67, '让子弹飞', 8.8, '导演:姜文WenJiang 主演:姜文WenJiang/葛优YouGe/周润发Yun-F...', '2010 中国大陆 中国香港 剧情 喜剧 动作 西部', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p1512562287.jpg', '你给我翻译翻译，神马叫做TMD的惊喜。');
INSERT INTO `user` VALUES (68, '海豚湾', 9.3, '导演:路易·西霍尤斯LouiePsihoyos 主演:RichardO\'Barry/路易·西霍...', '2009 美国 纪录片', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p2559579779.jpg', '海豚的微笑，是世界上最高明的伪装。');
INSERT INTO `user` VALUES (69, '西西里的美丽传说', 8.9, '导演:朱塞佩·托纳多雷GiuseppeTornatore 主演:莫妮卡·贝鲁奇Monica...', '2000 意大利 美国 剧情 战争 情色', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p2441988159.jpg', '美丽无罪。');
INSERT INTO `user` VALUES (70, '情书', 8.9, '导演:岩井俊二ShunjiIwai 主演:中山美穗MihoNakayama/丰川悦司Ets...', '1995 日本 剧情 爱情', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p449897379.jpg', '暗恋的极致。');
INSERT INTO `user` VALUES (71, '拯救大兵瑞恩', 9, '导演:史蒂文·斯皮尔伯格StevenSpielberg 主演:汤姆·汉克斯TomHanks...', '1998 美国 剧情 历史 战争', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p1014542496.jpg', '美利坚精神输出大片No1.');
INSERT INTO `user` VALUES (72, '小鞋子', 9.2, '导演:马基德·马基迪MajidMajidi 主演:法拉赫阿米尔·哈什米安AmirFa...', '1997 伊朗 剧情 儿童 家庭', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p2173580536.jpg', '奔跑的孩子是天使。');
INSERT INTO `user` VALUES (73, '美国往事', 9.2, '导演:赛尔乔·莱翁内SergioLeone 主演:罗伯特·德尼罗RobertDeNiro...', '1984 美国 意大利 犯罪 剧情', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p477229647.jpg', '往事如烟，无处祭奠。');
INSERT INTO `user` VALUES (74, '音乐之声', 9, '导演:罗伯特·怀斯RobertWise 主演:朱莉·安德鲁斯JulieAndrews/克...', '1965 美国 剧情 传记 爱情 歌舞', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p2189265302.jpg', '用音乐化解仇恨，让歌声串起美好。');
INSERT INTO `user` VALUES (75, '穿条纹睡衣的男孩', 9.1, '导演:马克·赫尔曼MarkHerman 主演:阿萨·巴特菲尔德AsaButterfield...', '2008 英国 美国 剧情 战争', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p1473670352.jpg', '尽管有些不切实际的幻想，这部电影依旧是一部感人肺腑的佳作。');
INSERT INTO `user` VALUES (76, '致命魔术', 8.9, '导演:克里斯托弗·诺兰ChristopherNolan 主演:休·杰克曼HughJackman...', '2006 美国 英国 剧情 悬疑 惊悚', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p480383375.jpg', '孪生蝙蝠侠大战克隆金刚狼。');
INSERT INTO `user` VALUES (77, '七宗罪', 8.8, '导演:大卫·芬奇DavidFincher 主演:摩根·弗里曼MorganFreeman/布...', '1995 美国 剧情 犯罪 悬疑 惊悚', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p457631605.jpg', '警察抓小偷，老鼠玩死猫。');
INSERT INTO `user` VALUES (78, '低俗小说', 8.8, '导演:昆汀·塔伦蒂诺QuentinTarantino 主演:约翰·特拉沃尔塔JohnTra...', '1994 美国 剧情 喜剧 犯罪', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p1910902213.jpg', '故事的高级讲法。');
INSERT INTO `user` VALUES (79, '沉默的羔羊', 8.8, '导演:乔纳森·戴米JonathanDemme 主演:朱迪·福斯特JodieFoster/安...', '1991 美国 剧情 犯罪 惊悚', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p1593414327.jpg', '安东尼·霍普金斯的顶级表演。');
INSERT INTO `user` VALUES (80, '被嫌弃的松子的一生', 8.9, '导演:中岛哲也TetsuyaNakashima 主演:中谷美纪MikiNakatani/瑛太E...', '2006 日本 剧情 歌舞', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p884763596.jpg', '以戏谑来戏谑戏谑。');
INSERT INTO `user` VALUES (81, '蝴蝶效应', 8.8, '导演:埃里克·布雷斯EricBress/J·麦基·格鲁伯J.MackyeGruber 主...', '2004 美国 加拿大 剧情 悬疑 科幻 惊悚', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p2209066019.jpg', '人的命运被自己瞬间的抉择改变。');
INSERT INTO `user` VALUES (82, '绿皮书', 8.9, '导演:彼得·法雷里PeterFarrelly 主演:维果·莫腾森ViggoMortensen/...', '2018 美国 剧情 喜剧 传记', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p2549177902.jpg', '去除成见，需要勇气。');
INSERT INTO `user` VALUES (83, '春光乍泄', 8.9, '导演:王家卫KarWaiWong 主演:张国荣LeslieCheung/梁朝伟TonyLeu...', '1997 中国香港 日本 韩国 剧情 爱情 同性', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p465939041.jpg', '爱情纠缠，男女一致。');
INSERT INTO `user` VALUES (84, '禁闭岛', 8.8, '导演:MartinScorsese 主演:莱昂纳多·迪卡普里奥LeonardoDiCaprio/...', '2010 美国 剧情 悬疑 惊悚', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p1832875827.jpg', '昔日翩翩少年，今日大腹便便。');
INSERT INTO `user` VALUES (85, '心灵捕手', 8.9, '导演:格斯·范·桑特GusVanSant 主演:马特·达蒙MattDamon/罗宾·...', '1997 美国 剧情', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p480965695.jpg', '人生中应该拥有这样的一段豁然开朗。');
INSERT INTO `user` VALUES (86, '布达佩斯大饭店', 8.8, '导演:韦斯·安德森WesAnderson 主演:拉尔夫·费因斯RalphFiennes/...', '2014 美国 德国 英国 剧情 喜剧 冒险', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p2178872593.jpg', '小清新的故事里注入了大历史的情怀。');
INSERT INTO `user` VALUES (87, '勇敢的心', 8.9, '导演:梅尔·吉布森MelGibson 主演:梅尔·吉布森MelGibson/苏菲·玛...', '1995 美国 动作 传记 剧情 历史 战争', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p1374546770.jpg', '史诗大片的典范。');
INSERT INTO `user` VALUES (88, '剪刀手爱德华', 8.7, '导演:蒂姆·波顿TimBurton 主演:约翰尼·德普JohnnyDepp/薇诺娜·...', '1990 美国 剧情 奇幻 爱情', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p480956937.jpg', '浪漫忧郁的成人童话。');
INSERT INTO `user` VALUES (89, '海蒂和爷爷', 9.2, '导演:阿兰·葛斯彭纳AlainGsponer 主演:阿努克·斯特芬AnukSteffen/...', '2015 德国 瑞士 南非 剧情 冒险 家庭', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p2554525534.jpg', '如果生活中有什么使你感到快乐，那就去做吧！不要管别人说什么。');
INSERT INTO `user` VALUES (90, '阿凡达', 8.7, '导演:詹姆斯·卡梅隆JamesCameron 主演:萨姆·沃辛顿SamWorthington...', '2009 美国 英国 动作 科幻 冒险', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p2180085848.jpg', '绝对意义上的美轮美奂。');
INSERT INTO `user` VALUES (91, '天使爱美丽', 8.7, '导演:让-皮埃尔·热内Jean-PierreJeunet 主演:奥黛丽·塔图AudreyTau...', '2001 法国 德国 喜剧 爱情', 'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p2447590313.jpg', '法式小清新。 ');
INSERT INTO `user` VALUES (92, '摩登时代', 9.3, '导演:查理·卓别林CharlesChaplin 主演:查理·卓别林CharlesChaplin...', '1936 美国 剧情 喜剧 爱情', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p2263408369.jpg', '大时代中的人生，小人物的悲喜。');
INSERT INTO `user` VALUES (93, '加勒比海盗', 8.7, '导演:戈尔·维宾斯基GoreVerbinski 主演:约翰尼·德普JohnnyDepp/...', '2003 美国 动作 冒险 奇幻', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p1596085504.jpg', '约翰尼·德普的独角戏。');
INSERT INTO `user` VALUES (94, '致命ID', 8.8, '导演:詹姆斯·曼高德JamesMangold 主演:约翰·库萨克JohnCusack/雷...', '2003 美国 剧情 悬疑 惊悚', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p2558364386.jpg', '最不可能的那个人永远是最可能的。');
INSERT INTO `user` VALUES (95, '喜剧之王', 8.7, '导演:周星驰StephenChow/李力持Lik-ChiLee 主演:周星驰StephenCh...', '1999 中国香港 喜剧 剧情 爱情', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p2579932167.jpg', '我是一个演员。');
INSERT INTO `user` VALUES (96, '断背山', 8.8, '导演:李安AngLee 主演:希斯·莱杰HeathLedger/杰克·吉伦哈尔Jake...', '2005 美国 加拿大 剧情 爱情 同性 家庭', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p513535588.jpg', '每个人心中都有一座断背山。');
INSERT INTO `user` VALUES (97, '幽灵公主', 8.9, '导演:宫崎骏HayaoMiyazaki 主演:松田洋治YôjiMatsuda/石田百合...', '1997 日本 动画 奇幻 冒险', 'https://img9.doubanio.com/view/photo/s_ratio_poster/public/p1613191025.jpg', '人与自然的战争史诗。');
INSERT INTO `user` VALUES (98, '杀人回忆', 8.8, '导演:奉俊昊Joon-hoBong 主演:宋康昊Kang-hoSong/金相庆Sang-kyun...', '2003 韩国 犯罪 剧情 悬疑 惊悚', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p2326071698.jpg', '关于连环杀人悬案的集体回忆。');
INSERT INTO `user` VALUES (99, '入殓师', 8.8, '导演:泷田洋二郎YôjirôTakita 主演:本木雅弘MasahiroMotoki/...', '2008 日本 剧情', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p594972928.jpg', '死可能是一道门，逝去并不是终结，而是超越，走向下一程。');
INSERT INTO `user` VALUES (100, '狩猎', 9.1, '导演:托马斯·温特伯格ThomasVinterberg 主演:麦斯·米科尔森MadsMik...', '2012 丹麦 瑞典 剧情', 'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p1546987967.jpg', '人言可畏。');
COMMIT;

SET FOREIGN_KEY_CHECKS = 1;
