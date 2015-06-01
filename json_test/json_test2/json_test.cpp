/*************************************************************************
    > File Name: json_test.cpp
    > Author: 时中贺
    > Mail: shi_zhonghe@163.com 
    > Created Time: 2015年05月31日 星期日 20时51分41秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<json/json.h>

void readJson()
{//从字符串中读取到json对象，并获取json对象内容
	std::cout << "----------readJson()----------" << std::endl;
	std::string strValue = "{\"name\":\"json\",\"array\":[{\"cpp\":\"json.cpp\"},{\"java\":\"jsoninjava\"},{\"php\":\"support\"}],\"id\":123}";

	Json::Reader reader;//解析json
	Json::Value value;	//定义一个json格式的对象

	if(reader.parse(strValue, value))//使用解析json中的parse方法解析json到value
	{
		std::string out = value["name"].asString();
		std::cout << out << std::endl;
		const Json::Value arrayObj = value["array"];
		Json::Value::const_iterator iter = arrayObj.begin();//使用迭代器访问json
		for(iter; iter != arrayObj.end(); ++iter)
		{
			if(!(*iter).isMember("cpp"))
				continue;
			out.clear();
			out = (*iter)["cpp"].asString();//把结果转换成string类型，取得json中的数据
			std::cout << out << std::endl;
		}

		int id = value["id"].asInt();
		std::cout << "id : " << id << std::endl;
	}
	else
	{
		std::cout << "json格式错误！" << std::endl;
	}
}

void writeJson()
{//把内容写到json对象中去
	std::cout << "----------writeJson()----------" << std::endl;
	Json::Value root;
	Json::Value arrayObj;
	Json::Value item;

	item["cpp"] = "jsoncpp";
	item["java"] = "jsoninjava";
	item["php"] = "support";
	arrayObj.append(item);

	root["name"] = "json";
	root["array"] = arrayObj;

	std::string styledOut = root.toStyledString();

	std::cout << styledOut << std::endl;
}

void writeJson_toFile(const char* fastJson_path, const char* styledJson_path)
{//以两种方式写入文件
	std::cout << "------writeJson_toFile()------" << std::endl;
	Json::Value root;
	Json::Value arrayObj;
	Json::Value item;
	Json::FastWriter writerFast;
	Json::StyledWriter writerStyled;

	item["cpp"] = "jsoncpp";
	item["java"] = "jsoninjava";
	item["php"] = "support";
	arrayObj.append(item);

	root["name"] = "json";
	root["array"] = arrayObj;

	std::string json_str = writerFast.write(root);//把json对象root写入string字符串

	std::ofstream fout(fastJson_path);
	if(!fout)
	{
		std::cout << "open fastJson_path error !" << std::endl;
		exit(0);
	}
	fout << json_str;

	fout.close();
	fout.clear();
	json_str.clear();
	fout.open(styledJson_path, std::ofstream::out | std::ofstream::trunc);
	json_str = writerStyled.write(root);//把json对象root写入字符串
	fout << json_str;
}
int main(void)
{//用于从字符串解析json，然后把内容写到json对象中,再写入文件
	readJson();
	writeJson();
	writeJson_toFile("./fast.Json", "./styled.json");
	return 0;
}
