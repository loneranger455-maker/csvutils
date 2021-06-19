#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<fstream>
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

class utilities{
    protected:
    
    public:
    vector <int> sorted(vector<string> pujan){
        vector<int> var2;
        int temp2;
        int value=0;
        string temp;
        for (int i=0;i<pujan.size();i++){
            var2.push_back(i);
        }
        for(int i=0;i<pujan.size();++i){
            value=i;
            for (int j=i+1;j<pujan.size();j++){
                // if (isdigit(pujan[i])){
                //     pujan[i]=stoi(pujan[i]);
                //     pujan[j]=stoi(pujan[j]);
                // }
                 
                if (pujan[i]>pujan[j]){
                    temp=pujan[i];
                    temp2=var2[i];
                    pujan[i]=pujan[j];
                    var2[i]=var2[j];
                    pujan[j]=temp;
                    var2[j]=temp2;
                }
            }

           
        }
        return(var2);
    }
};
class csvutils:utilities{
     bool checkmate=false;
     vector<string> title;
     vector <vector<string>> p;
     auto middle(auto var1){
        vector<vector<string>> output;
int l=0;

for (int i=0;i<var1.size();i++){
vector<string>tempr;
for (int j=0;j<p.size();j++){
    if (var1[i]!=j)
    continue;
    for (auto k=p[j].begin();k!=p[j].end();k++){
        // cout<<*k<<endl;
        tempr.push_back(*k);
    }

}
output.push_back(tempr);
}
return output;
    }
    public:
    bool checker=true;
    
   
    string str1;
    vector<vector <string>>csvreader(string a){
            fstream f1;
    string line;
    f1.open(a);
    while (getline(f1,line)){


        string temp="";
        int k=0;
        vector<string> finalone;
     
        int i;
        // cout<<a<<endl;
        for(i=0;i<line.size();i++){
            if (line[i]==','){
                  if (checker){
            title.push_back(temp);
           
        }
        else
                finalone.push_back(temp);
                
                temp="";
                k=0;
                continue;
            }
            temp.push_back(line[i]);
            k+=1;


        }
        if (checker)
        title.push_back(temp);
        else{
        finalone.push_back(temp);
        
        p.push_back(finalone);}
        checker=false;
        }
        f1.close();
        checkmate=true;
        return p;

    }
    void csvwrite(vector<vector<string>>p,string nameoffile,vector<string>l){
      fstream file1;
      file1.open(nameoffile,ios::trunc|ios::out);
      for (auto q=l.begin();q!=l.end();++q){
          str1=str1+*q;
          if (q+1!=l.end())
        str1=str1+",";
      }
      file1<<str1<<endl;
      str1="";
for(auto i=0;i<p.size();++i){
    for (auto j=p[i].begin();j!=p[i].end();j++){
        str1=str1+*j;
        if (j+1!=p[i].end())
        str1=str1+",";
    }
    file1<<str1<<endl;
    str1="";
}
file1.close();
    }

vector<string> extract_data(string param){
    if(!checkmate){
    cout<<"The file should be read first using csvreader"<<endl;
    exit(0);}
int index=0;
vector<string> output;
int k=0;
for(auto i=title.begin();i!=title.end();++i){
    
    if (*i==param)
    index=k;
    k+=1;
}
k=0;
for(auto i=0;i<=p.size();++i){
   for (auto j=p[i].begin();j!=p[i].end();++j){
       if (k==index)
       output.push_back(*j);
       k+=1;
    
   }
   k=0;
    }
    return output;
}


vector<vector<string>>  sort(string data){
      if(!checkmate){
    cout<<"The file should be read first using csvreader"<<endl;
    exit(0);}
auto var1=this->sorted(this-> extract_data(data));
return middle(var1);
}
auto shuffle(){
    if(!checkmate){
    cout<<"The file should be read first using csvreader";
    exit(0);}
    srand(time(NULL));
    int n=p.size();
    vector <string> temp;
     for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        temp=p[i];
        p[i]=p[j];
        p[j]=temp;
        
    }
    return(p);
}

vector<vector<string>> deleteline(int line){
      if(!checkmate){
    cout<<"The file should be read first using csvreader"<<endl;
    exit(0);}
    vector<vector<string>> temp;
    for(int i=0;i<p.size();i++){
        if (i!=line-1){
            temp.push_back(p[i]);
        }

    }
    p=temp;
    return p;
}

vector<vector<string>> replaceline(int line,vector<string> value){
      if(!checkmate){
    cout<<"The file should be read first using csvreader"<<endl;
    exit(0);}
     vector<vector<string>> temp;
    for(int i=0;i<p.size();i++){
        if (i==line-1){
            temp.push_back(value);
        }
        else
        temp.push_back(p[i]);
        p=temp;
        return p;
    }
    p=temp;
    return p;
}
vector<vector<string>> appendline(int line,vector<string> value){
      if(!checkmate){
    cout<<"The file should be read first using csvreader"<<endl;
    exit(0);}
     vector<vector<string>> temp;
    for(int i=0;i<p.size();i++){
        if (i==line-1){
            temp.push_back(value);
        }
        temp.push_back(p[i]);
    }
    p=temp;
    return p;
}


};

