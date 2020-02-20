#include<bits/stdc++.h>
using namespace std;

string in_name[]={"a_example.txt","b_read_on.txt","c_incunabula.txt","d_tough_choices.txt","e_so_many_books.txt","f_libraries_of_the_world.txt"};
string out_name[]={"1.out","2.out","3.out","4.out","5.out","6.out"};

struct Book{
    int id;
    long long int score;
};
#define mx 100005
Book books[mx];
struct library{
    int bnum;
    int signup;
    int ship;
    int id;
    vector<Book>lbook;
    long long  int bookscore;
    void update(){
        bookscore=0;
        for(int i=0;i<bnum;i++){
            bookscore+=books[lbook[i].id].score;
        }
    }
};

struct Solution{
    vector<int>sent;
    int libid;
};

long long int maxx(long long int a, long long int b)
{
	if(a>b) return a; return b;
}

map<int,int>sentbook;

bool cmp(library a,library b){
   /* if(a.bookscore!=b.bookscore)
    return a.bookscore>b.bookscore;
    else if(a.signup!=b.signup){
        return a.signup<b.signup;
    }
    else{
        return a.ship>b.ship;
    }*/

    long long x=a.signup+floor(a.bookscore/(1.0*a.ship));
    long long y=b.signup+floor(b.bookscore/(1.0*b.ship));
    return x<y;
    
}

bool cmpbook(Book a,Book b){
    return a.score>b.score;
}


library lbra[mx];
void solution(int cs){
        freopen(in_name[cs].c_str(),"r",stdin);
        freopen(out_name[cs].c_str(),"w",stdout);
    	sentbook.clear();

        int book,lib,day;
        cin>>book>>lib>>day;

        
        for(int i=0;i<book;i++){
            cin>>books[i].score;
            books[i].id=i;
            sentbook[i]=0;
        }

        
     //   cout<<cs<<"x"<<endl;
        for(int i=0;i<lib;i++){
            cin>>lbra[i].bnum>>lbra[i].signup>>lbra[i].ship;
            lbra[i].id=i;
            lbra[i].bookscore=0;
            lbra[i].lbook.clear();
            for(int j=0;j<lbra[i].bnum;j++){
                int bookid;
                cin>>bookid;
                lbra[i].bookscore+=books[bookid].score;
                lbra[i].lbook.push_back(books[bookid]);
            }
            sort(lbra[i].lbook.begin(),lbra[i].lbook.end(),cmpbook);

        }
        sort(lbra,lbra+lib,cmp);
        vector<Solution>solve;
        int co=0;
        int it=lib/;

        int c=it;


        for(int i=0;i<lib;i++){
            
            vector<int>sent;
            for(int j=0;j<lbra[i].bnum;j++){
                if(sentbook[lbra[i].lbook[j].id]==0){
                    sent.push_back(lbra[i].lbook[j].id);
                    books[lbra[i].lbook[j].id].score=0;
                    sentbook[lbra[i].lbook[j].id]=1;
                }
            }
            for(int j=i+1;j<lib;j++){
                lbra[j].update();
            }
            if(i==c and i!=lib-1){
                c+=it;
                sort(lbra+i+1,lbra+lib,cmp);
            }
            if(sent.size()!=0){
                co++;
                Solution s;
                s.libid=lbra[i].id;
                s.sent=sent;
                solve.push_back(s);
            }
            
        }
        cout<<solve.size()<<endl;
        for(int i=0;i<solve.size();i++){
            cout<<solve[i].libid<<" "<<solve[i].sent.size()<<endl;
            for(int j=0;j<solve[i].sent.size();j++){
                cout<<solve[i].sent[j]<<" ";
            }
            cout<<endl;
        }

}
int main(){
    for(int cs=0;cs<6;cs++){
        solution(cs);

    }
}