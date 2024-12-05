#include <iostream>
#include <regex>
#include <string>
#include <vector>

std::vector<std::string> a;
std::string input;
std::vector<std::string> b;
std::smatch matches ,submatch;

int acc = 0;

const std::regex pattern("mul\\(([0-9]{1,3}),([0-9]{1,3})\\)"); 
const std::regex subpattern("([0-9]{1,3})");

int main(){
  while(std::cin >> input){ a.push_back(input);}
 
for(auto& var : a)
{
  std::string text = var;
  std::sregex_iterator it(text.begin(), text.end(), pattern);
  std::sregex_iterator end;
  while (it != end)
  {
    b.push_back(it->str());
    ++it;
  }
}
  for (auto& match : b){
    std::sregex_iterator sub(match.begin(),match.end(), subpattern);
    std::sregex_iterator end;
    std::vector<int> both;
    while(sub != end)
    {
    both.push_back(stoi(sub -> str()));
    sub++;
    } 
    acc += both[0]*both[1];
  }
std::cout << acc << " :acc";
return 0;
}

