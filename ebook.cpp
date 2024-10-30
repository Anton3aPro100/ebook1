#include <vector>
#include <iostream>
#include <utility>
#include <iomanip>

//enum class Request { READ, CHEER };

using namespace std;

pair<string, string> SplitString(const string& str) {
    size_t space_pos = str.find(' '); 

    if (space_pos == std::string::npos) {
        return {str, ""};
    }

    string first_part = str.substr(0, space_pos);
    string second_part = str.substr(space_pos + 1);

    return {first_part, second_part}; 
}

class EBook{
    public:
        EBook() : users_(100001,0), pages_(1001,0){}
    
        void Read(int user, int page){
            
            int last_page = users_[user];
            if (last_page == 0){
                users_count_++;
            }
            users_[user] = page;
            for (int i = last_page + 1; i <= page; ++i){
                pages_[i]++;
            }
            
            
        }
        void Cheer(int user){
            if (users_[user] == 0){
                cout<<0;
            }
            else{
                if (users_count_ == 1){
                    cout<<1;
                }
                else{
                    int page = users_[user];
                    double res = (users_count_ - pages_[page]+0.0) / (users_count_ - 1.0);
                    //cout<<user<<" "<<users_[user]<<" "<<pages_[users_[user]]<<" "<<users_count_ - pages_[page]<<" "<< users_count_ - 1<<endl;
                    
                    cout << setprecision(6) << res;
                }
            }
            
            cout<<endl;
        }
        
    private:
        vector<short> users_;
        vector<int> pages_;
        int users_count_ = 0;
};

int main() {
    
    int q;
    cin >> q;
    EBook book;
    for (int i = 0; i <= q; ++i){
        string s;
        getline(cin,s);
        //cout<<i<<"---"<<s<<endl;
        pair<string, string> request = SplitString(s);
        if (request.first == "READ"){
            pair<string,string> pair_num = SplitString(request.second);
            int user = stoi(pair_num.first);
            int page = stoi(pair_num.second);
            book.Read(user,page);
        }
        if (request.first == "CHEER"){
            int user = stoi(request.second);
            book.Cheer(user);
        }
        
    }
}