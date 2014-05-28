#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
bool GetWord(const char* str, char* word)
{
	static const char* p;
	int i;
	if (str)
	{
		p=str;//p就是那整个sentence“To be or ...a problem”
		//cout<<p<<endl;
	}
	for (i=0;!isalpha(p[i])&& p[i];++i);
	if (p[i]==0)
	{
		//cout<<"the end of the word"<<endl;
		return false;
	}
	p+=i;
	//cout<<"               (1)p+=i; the p is :"<<p<<endl;
	//cout<<"               (1)p+=i;the i is: "<<i<<endl;
	for (i=0;isalpha(p[i])&&p[i];++i);
	strncpy(word,p,i);
	word[i]=0;
	p+=i;
	//cout<<"               (2)p+=i; the p is: "<<p<<endl;
	//cout<<"               (2)p+=i;the i is : "<<i<<endl;
	return true;
}
int main()
{
	const char *sentence = "To be or not to be, is a problem.";
	char word[100];
	bool b=GetWord(sentence,word);
	while (b)
	{
		cout<<word<<endl;
		b=GetWord(NULL, word);
	}
}