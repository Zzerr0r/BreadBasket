#include <iostream>
#include <vector>

using namespace std;


vector<int> concatinate(int*p,int length) {

    int sum = 0;
    vector <int> bar;

    for (int i =0 ; i<length; i++){
        int act = *(p+i) ;                         // 15,-17, 20, 5, 40, -10
        if (sum == 0){
            sum+= act;
        }
        else if (sum > 0 ) {
            if (act >= 0 ){
                sum += act;
            }
            else {
                bar.push_back(sum);
                sum =act ;

            }

        }
         else if (sum<0){
            if (act < 0){
                sum += act;
            }
            else {
                bar.push_back(sum);
                sum = act;
            }

        }

    }

    if (sum > 0) bar.push_back(sum);
    if (bar.at(0) <0 ) bar.erase(bar.begin()+0);
    //Ausgabe



    return bar;


}

void simplify (){


}
int main() {

    int foo [] = {1, -52	,39	,-12  ,3, 25	,-33	,5	,-73	,-34,500,-1000	,80}; // { 15,-17, 20, 5, 40, -10 };
    int n =sizeof(foo)/sizeof(int);
    int max = 0;
    for (int i=0; i<n; i++ ) {
        for ( int j =i; j<n; j++ ) {
            int sum = 0;
            for ( int k=i; k<j; k++ ) {
                sum += foo[k];
                if(sum>max){
                    max=sum;
                }
            }
        }
    }
    auto bar  = concatinate(&foo[0],n);
    for ( int i =0; i<bar.size();i++){
        cout << bar.at(i) << " ";
    }
    return 0;
}