#include"BsTree.h"
#include<string>
#include<vector>
//int main()
//{
//	BSTree<int> s;
//	int a[]= {8, 3, 1, 10, 1, 6, 4, 7, 14, 13}; 
//	for (auto e : a)
//	{
//		s.insert(e);
//	}
//	s.Inorder();
//	//s.erase(8);
//	//s.Inorder();
//	for (auto e : a)
//	{
//		s.erase(e);
//		s.Inorder();
//	}
//	//cout << s.find(0) << endl;
//	return 0;
//}
//int main()
//{
//	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
//my_multi::BSTree<string, int> countTree;
//for (const auto& str : arr)
//{
//	// 先查找水果在不在搜索树中
//	// 1、不在，说明水果第一次出现，则插入<水果, 1>
//	// 2、在，则查找到的结点中水果对应的次数++
//	//BSTreeNode<string, int>* ret = countTree.Find(str);
//	auto ret = countTree.find(str);
//	if (ret == NULL)
//	{
//	countTree.insert(str, 1);
//	}
//	else
//	{
//	ret->_size++;
//	}
//	}
//	countTree.Inorder();
//	return 0;
//}
int main()
{
    
    vector<std::string> s1 = {
        // 前100个使用频率最高的英文单词（按COCA语料库排序）
        "the", "be", "to", "of", "and", "a", "in", "that", "have", "I",
        "it", "for", "not", "on", "with", "he", "as", "you", "do", "at",
        "this", "but", "his", "by", "from", "they", "we", "say", "her", "she",
        "or", "an", "will", "my", "one", "all", "would", "there", "their", "what",
        "so", "up", "out", "if", "about", "who", "get", "which", "go", "me",
        "when", "make", "can", "like", "time", "no", "just", "him", "know", "take",
        "people", "into", "year", "your", "good", "some", "could", "them", "see", "other",
        "than", "then", "now", "look", "only", "come", "its", "over", "think", "also",
        "back", "after", "use", "two", "how", "our", "work", "first", "well", "way",
        "even", "new", "want", "because", "any", "these", "give", "day", "most", "us"
    };
    std::vector<std::string> s2 = {
        // 对应英文的中文释义
        "这/那个", "是/存在", "到/向", "属于/关于", "和/并且", "一个", "在...里面", "那个/那", "有/拥有", "我",
        "它", "为了/对于", "不/没有", "在...上面", "和...一起", "他", "作为/像", "你", "做/干", "在（位置）",
        "这个/这", "但是", "他的", "通过/被", "从...来", "他们", "我们", "说/讲", "她的", "她",
        "或者", "一个（元音前）", "将/会", "我的", "一/一个", "全部/所有", "会/将", "那里/在那里", "他们的", "什么",
        "如此/所以", "向上", "出去/外面", "如果", "关于/大约", "谁", "得到/获取", "哪一个", "去/走", "我（宾格）",
        "当...时", "制作/使", "能/可以", "喜欢/像", "时间/次", "不/没有", "仅仅/只是", "他（宾格）", "知道/了解", "拿/取",
        "人们/人", "进入/到...里面", "年", "你的/你们的", "好的", "一些/若干", "能够/可以", "他们（宾格）", "看见/明白", "其他的",
        "比", "然后/那时", "现在", "看/看起来", "仅仅/只", "来/来到", "它的", "超过/在...上面", "认为/思考", "也/同样",
        "回来/向后", "在...之后", "使用/利用", "二/两个", "怎样/如何", "我们的", "工作/劳动", "第一/首先", "很好地/健康的", "方式/道路",
        "甚至/即使", "新的", "想要/希望", "因为", "任何/一些", "这些", "给/给予", "天/日", "大多数/大部分", "我们（宾格）"
    };
    my_multi::BSTree<string, string> word;
    vector<string>::iterator it1 = s1.begin();
   vector<string>::iterator it2 = s2.begin();
    while (it1 != s1.end()&&it2!=s2.end())
    {
        /*cout << *it1 << endl;
        ++it1;*/
       word.insert(*it1,*it2);
       ++it1;
       ++it2;
    }
    //word.Inorder();
    string s;
    cin >> s;
    auto p = word.find(s);
    if (p==nullptr)
    {
        cout << "没找到" << endl;
    }
    else

    {
        cout << p->_val << ":" << p->_size;
    }
	return 0;
}