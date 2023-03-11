#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include <fstream>
#include <utility>
#include <string>

using namespace std;

string inttostring(int n)
{
    if(n==0)
        return "0";

    string ans="";
    while(n>0)
    {
        ans=(char)(48+(n%10))+ans;
        n/=10;
    }
    return ans;
}

int strtoint(string str)
{
    int ans=0;

    for(int i=0; i<str.length(); i++)
    {
        ans*=10;
        ans+=(int)(str[i])-48;
    }

    return ans;
}
vector<int> splitnumbers(string str)
{
    vector<int> ans;
    int n=str.length();

    int index=0;
    while(index<n)
    {
        string tmp="";
        while(index<n && str[index]!=',' && str[index]!=' ')
        {
           tmp+=str[index++]; 
        }
        index++;
        if(tmp!="")
            ans.push_back(strtoint(tmp));
    }
    return ans;
}

int main()
{
    fstream file;
    file.open("input", ios::in);

    string str;
    getline(file,str);

    vector<vector<int>> values;
    int n=strtoint(str);
    
    vector<pair<int,int>> arrange;
    for(int i=0; i<n; i++)
    {
        getline(file,str);
        vector<int> vals=splitnumbers(str);

        arrange.push_back(make_pair(vals[1],i));
        values.push_back(vals);
    }

    vector<vector<int>> copy;
    sort(arrange.begin(), arrange.end(),greater<pair<int, int> >());

    for(auto P : arrange)
        copy.push_back(values[P.second]);
    
    arrange.clear();
    values=copy;
    copy.clear();

    for(int i=0; i<n; i++)
        arrange.push_back(make_pair(values[i][0],i));

    sort(arrange.begin(), arrange.end());
    for(auto P : arrange)
        copy.push_back(values[P.second]);

    file.close();

    ofstream OUTPUT("output.txt");

    for(int i=0; i<n; i++)
    {
        string line="";
        line+=inttostring(copy[i][0])+" "+inttostring(copy[i][1])+" "+inttostring(copy[i][2]);

        OUTPUT<<line<<endl;
    }
    OUTPUT.close();
    
    return 0;
}