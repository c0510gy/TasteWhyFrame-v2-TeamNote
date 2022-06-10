#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <complex>
#define M_PI 3.14159265358979323846

using namespace std;

using pii=pair<int,int>;
using ll=long long;

void fft(vector<complex<double>>& v, bool inverse)
{
    int n=v.size();
    for(int i=0; i<n; i++){
        int j=0;
        for(int jj=1, jjj=i; jj<n; jj<<=1,jjj>>=1){
            j<<=1;
            if(jjj&1) j+=1;
        }
        if(i<j) swap(v[i],v[j]);
    }
    for(int i=2; i<=n; i<<=1){
        complex<double> tmp2={cos(-2*M_PI/i*((inverse)?-1:1)),sin(-2*M_PI/i*((inverse)?-1:1))};
        for(int j=0; j<n; j+=i){
            complex<double> tmp1={1,0};
            for(int k=0; k<i/2; k++){
                complex<double> a=v[j+k];
                complex<double> b=v[j+i/2+k];
                v[j+k]=a+tmp1*b;
                v[j+i/2+k]=a-tmp1*b;
                tmp1*=tmp2;
            }
        }
    }
    if(inverse) for(int i=0; i<n; i++) v[i]/=n;
}

void multiply(vector<int>& a, vector<int>& b, vector<int>& ret)
{
    int n=1;
    vector<complex<double>> fa(a.begin(),a.end());
    vector<complex<double>> fb(b.begin(),b.end());
    while(n<max(fa.size(),fb.size())) n<<=1;
    n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa,false);
    fft(fb,false);
    for(int i=0; i<n; i++) fa[i]*=fb[i];
    fft(fa,true);
    ret.resize(n);
    for(int i=0; i<n; i++) ret[i]=(int)(fa[i].real()+((fa[i].real()>0)?0.5:-0.5));
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cin>>n;
    vector<int> a(2*n);
    vector<int> b(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
        a[i+n]=a[i];
    }
    for(int i=0; i<n; i++) cin>>b[n-1-i];
    vector<int> ret;
    // Discrete Convolution
    multiply(a,b,ret);
    int answer=0;
    for(int i=0; i<n; i++) answer=max(answer,ret[n-1+i]);
    cout<<answer;

    return 0;
}
