/*************************************************************************
  > File Name: json_test.cpp
  > Author: 时中贺
  > Mail: shi_zhonghe@163.com 
  > Created Time: 2015年05月31日 星期日 13时59分22秒
 ************************************************************************/

#include<iostream>
#include <json/json.h>
#include <string>

int main()
{

	std::string test ="{\"id\":1,\"name\":\"kurama\"}";
	Json::Reader reader;
	Json::Value value;
	if(reader.parse(test,value))
	{

		if(!value["id"].isNull())
		{

			std::cout << value["id"].asInt() << std::endl;
			std::cout << value["name"].asString()<< std::endl;
		}
	}
	return 0;
}
