## Ответы на вопросы к лабе3
# //------------------------------------------------------- 0
# //------------------------------------------------------- 1
```bash
int F1(int n) {
    if (n==1) return 1;
    return (n * F1(n-1)); 
}
```
<div>
<h>Ответ на 1 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 2
```bash
int F2(int A[],int a, int b) { 
    if (a>b) return 0; 
    if (a==b) return A[a];
    int m=(a+b)/2;
    int v1=F2(A,a,m),v2=F2(A,m+1,b);
    return v1>v2 ? v1: v2; 
}
```
<div>
<h>Ответ на 2 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 3
```bash
int F3(int A[],int a, int b) {
    if (a>b) return 0; 
    if (a==b) return A[a];
    int m=(a+b)/2;
    return F3(A,a,m)+F3(A,m+1,b); 
}
```
<div>
<h>Ответ на 3 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 4
```bash
void F4(int A[], int a, int b) {
    int i,j,mode;
    if (a>=b) return;
    for (i=a, j=b, mode=1; i != j; mode >0 ? i++ : j--)
    if (A[i] > A[j]) {
        int c;
        c=A[i]; A[i]=A[j]; A[j]=c; mode = -mode;
    }
    F4(A,a,i-1); F4(A,i+1,b); 
}
```
<div>
<h>Ответ на 4 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 5
```bash
int F5(int A[], int a, int b, int val) {
    int i,j,mode;
    if (a>=b) return -1;
    int m=(a+b)/2;
    if (val==A[m]) return m;
    if (val<A[m]) return F5(A,a,m-1,val);
    return F5(A,m+1,b,val);
}
```
<div>
<h>Ответ на 5 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 6
```bash
long F6(int n) {
    if (n==0 || n==1) return 1;
    return F6(n-1)+F6(n-2);
}
```
<div>
<h>Ответ на 6 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 7
```bash
char *F7(char *p, char *s) {
    if ( *s =='\0') return p;
    *p++ = *s;
    p=F7(p, s+1);
    *p++ = *s;
    return p;
}
void z7() { char *q, S[80]; *F7(S, "abcd")=0; }
```
<div>
<h>Ответ на 7 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 8
```bash
void F8(char *&p, char *s) {
    if ( *s =='\0') return;
    *p++ = *s;
    F8(p, s+1);
    *p++ = *s;
}
void z8() {char *q, S[80]; q = S; F8(q,"abcd"); *q=0; 
```
<div>
<h>Ответ на 8 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 9
```bash
double F9(double *pk, double x, int n) {
    if (n==0) return(*pk);
    return *pk + x *F9(pk+1,x,n-1);
}
void z9() {double B[]={5.,0.7,4.,3.} ,X=3.,Y=F9(B,X,4); }
```
<div>
<h>Ответ на 9 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 10
```bash
void F10(int *p, int nn) {
    if (nn==1) {
        *p=0; return;
    }
    for (int i=2; nn % i !=0; i++);
    *p=i; F10(p+1,nn/i);
}
```
<div>
<h>Ответ на 10 вопрос</h>
<p></p>
</div>