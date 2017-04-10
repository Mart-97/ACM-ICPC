#include <bits/stdc++.h>
using namespace std;
#define dprint(v) cerr << #v"=" << v << endl //;)
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> ii;

//~ typedef complex<double> base; //menos codigo, pero mas lento
//elegir si usar complejos de c (lento) o estos
struct base{
    double r,i;
    base(double r=0, double i=0):r(r), i(i){}
    double real()const{return r;}
    void operator/=(const int c){r/=c, i/=c;}
};
base operator*(const base &a, const base &b){
    return base(a.r*b.r-a.i*b.i, a.r*b.i+a.i*b.r);}
base operator+(const base &a, const base &b){
    return base(a.r+b.r, a.i+b.i);}
base operator-(const base &a, const base &b){
    return base(a.r-b.r, a.i-b.i);}
vector<int> rev; vector<base> wlen_pw;
inline static void fft(base a[], int n, bool invert) {
    forn(i, n) if(i<rev[i]) swap(a[i], a[rev[i]]);
    for (int len=2; len<=n; len<<=1) {
        double ang = 2*M_PI/len * (invert?-1:+1);
        int len2 = len>>1;
        base wlen (cos(ang), sin(ang));
        wlen_pw[0] = base (1, 0);
        forr(i, 1, len2) wlen_pw[i] = wlen_pw[i-1] * wlen;
        for (int i=0; i<n; i+=len) {
            base t, *pu = a+i, *pv = a+i+len2,  *pu_end = a+i+len2, *pw = &wlen_pw[0];
            for (; pu!=pu_end; ++pu, ++pv, ++pw)
                t = *pv * *pw, *pv = *pu - t,*pu = *pu + t;
        }
    }
    if (invert) forn(i, n) a[i]/= n;}
inline static void calc_rev(int n){//precalculo: llamar antes de fft!!
    wlen_pw.resize(n), rev.resize(n);
    int lg=31-__builtin_clz(n);
    forn(i, n){
        rev[i] = 0;
        forn(k, lg) if(i&(1<<k)) rev[i]|=1<<(lg-1-k);
    }}
inline static void multiply(const vector<int> &a, const vector<int> &b, vector<int> &res) {
    vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
    int n=1; while(n < max(sz(a), sz(b))) n <<= 1; n <<= 1;
    calc_rev(n);
    fa.resize (n),  fb.resize (n);
    fft (&fa[0], n, false),  fft (&fb[0], n, false);
    forn(i, n) fa[i] = fa[i] * fb[i];
    fft (&fa[0], n, true);
    res.resize(n);
    forn(i, n) res[i] = int (fa[i].real() + 0.5); }
void toPoly(const string &s, vector<int> &P,char c,bool inv){//convierte un numero a polinomio
    P.clear();
    if(inv){
        dforn(i, sz(s)) P.pb(s[i] == c);
    } else {
        for(int i = 0; i<s.size(); i++){
            P.pb(s[i] == c);
        }
    }

}   
string ans;
void imprimir(const vector<int> &V){
    for(int i = 0; i<V.size(); i++){
        cout << V[i] << " ";
    }
    cout << endl;
}
void save(const string &v, int pos){
  for(int i = pos; i>=0; i--){
    ans.pb(v[i]);
  }
}
vector<int> a_a,a_c,a_g,a_t;
vector<int> b_a,b_c,b_g,b_t;
vector<int> res_a,res_c,res_g,res_t;
int main(){
    string ss,s;
    string tt,t;
    int tc = 0;
    while(!getline(cin,ss).eof()){
        cin >> tt;
        ans.clear();
        getchar();
        getchar();
        s = ss;
        t = tt;
        /*if(tt.size() > ss.size()){
            s = tt;
            t = ss;
        }
        if(tc > 0){
            printf("\n");
        }*/
        tc++;
        toPoly(s,a_a,'A',false);
        toPoly(s,a_c,'C',false);
        toPoly(s,a_g,'G',false);
        toPoly(s,a_t,'T',false);
        toPoly(t,b_a,'A',true);
        toPoly(t,b_c,'C',true);
        toPoly(t,b_g,'G',true);
        toPoly(t,b_t,'T',true);
        ///imprimir(a_a);
        multiply(b_a,a_a,res_a);
        multiply(b_c,a_c,res_c);
        multiply(b_g,a_g,res_g);
        multiply(b_t,a_t,res_t);
        ///cout<< res_a.size() << " " << res_c.size() << " " << res_t.size() << " " << res_g.size() << endl;
        /*imprimir(res_a);
        imprimir(res_c);
        imprimir(res_g);
        imprimir(res_t);*/
        int maximo = INT_MIN;
        int index;
        for(int i = 0; i<res_a.size(); i++){
            ///cout << res_t[i] +res_a[i]+res_c[i] + res_g[i]  << " ";
            int actual = res_t[i] +res_a[i]+res_c[i] + res_g[i] ;
            if(maximo <=actual ){
                maximo = actual;
                index = i;
            }
        }
        int ps,pt, p_s,i,p_t;
        if(maximo > 0){
          printf("%d\n",maximo);
          if(index <= s.size() - 1){
              ps  = s.size() - 1;
              while(ps>index){
                ans.pb(s[ps--]);
              }
              pt = t.size() - 1;
              while(pt >=0 && ps >= 0){
                if(s[ps] == t[pt]){
                  ans.pb(s[ps]);
                } else ans.pb('X');
                ps--;
                pt--;
              }
              if(ps < 0) save(t,pt);
              if(pt < 0) save(s,ps);

          }else{
              pt = t.size() -1;
              ps = s.size() - 1;
              int ptaux = s.size()-1;
              while(ptaux < index){
                ptaux++;
                ans.pb(t[pt]);
                pt--;
              } 
              while(ps >= 0 && pt >=0){
                if(s[ps] == t[pt]){
                  ans.pb(s[ps]);
                } else ans.pb('X');
                ps--;
                pt--;
              }
              if(ps < 0) save(t,pt);
              if(pt < 0) save(s,ps);
          }


          for(int i = ans.size()-1; i>=0; i--){
            printf("%c",ans[i]);
          }
            
        } else {
            printf("0\n") ;
            printf("No matches");
        }
        printf("\n\n");
    }
    return 0;
    
}
