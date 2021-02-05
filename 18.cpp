#include "bits/stdc++.h"
using namespace std;
string temp;
long long result = 0;
int poleZavorek1[10];
int poleZavorek2[10];
int poleCisel[30];
int pos=0;
string symboly;
char * expressionToParse;
double eval(string expr)
{
    string xxx; // Get Rid of Spaces
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] != ' ')
        {
            xxx += expr[i];
        }
    }

    string tok = ""; // Do parantheses first
    for (int i = 0; i < xxx.length(); i++)
    {
        if (xxx[i] == '(')
        {
            int iter = 1;
            string token;
            i++;
            while (true)
            {
                if (xxx[i] == '(')
                {
                    iter++;
                } else if (xxx[i] == ')')
                {
                    iter--;
                    if (iter == 0)
                    {
                        i++;
                        break;
                    }
                }
                token += xxx[i];
                i++;
            }
            cout << "(" << token << ")" << " == " << to_string(eval(token)) <<  endl;
            tok += to_string(eval(token));
        }
        tok += xxx[i];
    }

    for (int i = 0; i < tok.length(); i++)
    {
        if (tok[i] == '*')
        {
            return eval(tok.substr(0, i)) * eval(tok.substr(i+1, tok.length()-i-1));
        }
    }
    for (int i = 0; i < tok.length(); i++)
    {
        if (tok[i] == '+')
        {
            return eval(tok.substr(0, i)) + eval(tok.substr(i+1, tok.length()-i-1));
        }
    }
    return stod(tok.c_str());

}
int main(){
	ifstream infile("input18.txt");
	while(getline(infile,temp)){
		string opak = "";
		for(int i=temp.size()-1;i>=0;i--){
			if(temp[i]=='('){opak.push_back(')');continue;}
			if(temp[i]==')'){opak.push_back('(');continue;}
			opak.push_back(temp[i]);
		}
		result+=eval(opak);
	}
	cout << "Part 1: " <<result << endl;
	return 0;
}