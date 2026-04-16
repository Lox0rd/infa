## Ответы на вопросы к лабе3
# //------------------------------------------------------- 0
```bash
struct ltree{
    int val;
    ltree *child,*next; };
struct tree{
    int val;
    tree *ch[4]; };
struct tree1{
    int val;
    int n;
    tree1 *ch[10]; };
struct btree{
    int val;
    btree *l,*r; };
```
# //------------------------------------------------------- 1
```bash
int F1(ltree *p) {
    int n=1;
    for (ltree *q=p->child; q!=NULL; q=q->next)
    n+=F1(q);
    return n;
}
```
<div>
<h>Ответ на 1 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 2
```bash
int F2(ltree *p) {
    int n=p->val;
    for (ltree *q=p->child; q!=NULL; q=q->next)
    n+=F2(q);
    return n;
}
```
<div>
<h>Ответ на 2 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 3
```bash
int F3(ltree *p) {
    int n=p->val;
    for (ltree *q=p->child; q!=NULL; q=q->next) {
        int vv=F3(q);
        if (vv > n) n=vv;
    }
    return n;
}
```
<div>
<h>Ответ на 3 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 4
```bash
int F4(ltree *p){
    int n=0;
    for (ltree *q=p->child; q!=NULL; q=q->next) {
        int vv=F4(q); if (vv > n) n=vv;
    }
    return n+1;
}
```
<div>
<h>Ответ на 4 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 5
```bash
void F5(ltree *p, int l, int &m) {
    if (l > m) m=l;
    for (ltree *q=p->child; q!=NULL; q=q->next)
    F5(q,l+1,m);
}
```
<div>
<h>Ответ на 5 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 6
```bash
int F6(ltree *p, int l) {
    int n=l;
    for (ltree *q=p->child; q!=NULL; q=q->next)
    n+=F6(q,l+1);
    return n;
}
double main6(ltree *p) {
    return ((double)F6(p,1))/F1(p);
}
```
<div>
<h>Ответ на 6 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 7
```bash
int F7(ltree *p) {
    if (p->val > 6) return p->val;
    for (ltree *q=p->child; q!=NULL; q=q->next) {
        int vv=F7(q); if (vv!=-1) return vv;
    }
    return -1;
}
```
<div>
<h>Ответ на 7 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 8
```bash
int F8(btree *p) {
    if (p==NULL) return 0;
    return (1 + F8(p->r) + F8(p->l));
}
```
<div>
<h>Ответ на 8 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 9
```bash
int F9(btree *p) {
    if (p==NULL) return 0;
    int nr=F9(p->r);
    int nl=F9(p->l);
    return 1 + (nr>nl ? nr : nl);
}
```
<div>
<h>Ответ на 9 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 10
```bash
int F10(btree *p) {
    if (p==NULL) return 0;
    int m,n=p->val;
    if ((m=F10(p->r))>n) n=m;
    if ((m=F10(p->l))>n) n=m;
    return n;
}
```
<div>
<h>Ответ на 10 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 11
```bash
int F11(tree1 *p) {
    int s=1;
    for (int i=0;i < p->n; i++) s+=F11(p->ch[i]);
    return s;
}
```
<div>
<h>Ответ на 11 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 12
```bash
int F12(tree1 *p) {
    int s=p->val;
    for (int i=0;i < p->n; i++) s+=F12(p->ch[i]);
    return s;
}
```
<div>
<h>Ответ на 12 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 13
```bash
int F13(tree1 *p) {
    int s=p->val;
    for (int i=0;i < p->n; i++) {
        int vv=F13(p->ch[i]); 
        if (vv > s) s=vv;
    }
    return s;
}
```
<div>
<h>Ответ на 13 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 14
```bash
int F14(tree1 *p) {
    int s=0;
    for (int i=0;i < p->n; i++) {
        int vv=F14(p->ch[i]);
        if (vv > s) s=vv;
    }
    return s+1;
}
```
<div>
<h>Ответ на 14 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 15
```bash
void F15(tree1 *p, int l, int &m) {
    if (l > m) m=l;
    for (int i=0;i < p->n; i++) F15(p->ch[i],l+1,m);
}
```
<div>
<h>Ответ на 15 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 16
```bash
int F16(tree1 *p, int l) {
    int s=l;
    for (int i=0;i < p->n; i++)
    s+=F16(p->ch[i],l+1);
    return s;
}
double main16(tree1 *p) {
    return ((double)F16(p,1))/F11(p);
}
```
<div>
<h>Ответ на 16 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 17
```bash
int F17(tree1 *p) {
    if (p->val > 6) return p->val;
    for (int i=0;i < p->n; i++) {
        int vv=F17(p->ch[i]);
        if (vv!=-1) return vv;
    }
    return -1;
}
```
<div>
<h>Ответ на 17 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 18
```bash

```
<div>
<h>Ответ на 18 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 19
```bash

```
<div>
<h>Ответ на 19 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 20
```bash

```
<div>
<h>Ответ на 20 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 21
```bash
int F21(tree *p) {
    if (p==NULL) return 0;
    int s=1;
    for (int i=0; i<4; i++) s+=F21(p->ch[i]);
    return s;
}
```
<div>
<h>Ответ на 21 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 22
```bash
int F22(tree *p) {
    if (p==NULL) return 0;
    int s=p->val;
    for (int i=0; i<4; i++) s+=F22(p->ch[i]);
    return s;
}
```
<div>
<h>Ответ на 22 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 23
```bash
int F23(tree *p) {
    if (p==NULL) return 0;
    int s=p->val;
    for (int i=0; i<4; i++) {
        int vv=F23(p->ch[i]);
        if (vv > s) s=vv;
    }
    return s;
}
```
<div>
<h>Ответ на 23 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 24
```bash
int F24(tree *p){
    if (p==NULL) return 0;
    int s=0;
    for (int i=0; i<4; i++) {
        int vv=F24(p->ch[i]);
        if (vv > s) s=vv;
    }
    return s+1; 
}
```
<div>
<h>Ответ на 24 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 25
```bash
void F25(tree *p, int l, int &m) {
    if (p==NULL) return;
    if (l > m) m=l;
    for (int i=0; i<4; i++) F25(p->ch[i],l+1,m);
}
```
<div>
<h>Ответ на 25 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 26
```bash
int F26(tree *p, int l) {
    if (p==NULL) return 0;
    int s=l;
    for (int i=0; i<4; i++) s+=F26(p->ch[i],l+1);
    return s;
}
double main26(tree *p) {
    return ((double)F26(p,1))/F21(p);
}
```
<div>
<h>Ответ на 26 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 27
```bash
int F27(tree *p) {
    if (p->val > 6) return p->val;
    for (int i=0; i<4; i++) {
        int vv=F27(p->ch[i]); 
        if (vv!=-1) return vv;
    }
    return -1;
}
```
<div>
<h>Ответ на 27 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 28
```bash

```
<div>
<h>Ответ на 28 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 29
```bash

```
<div>
<h>Ответ на 29 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 30
```bash
int F30(int A[],int sz, int n) {
    if (n>=sz || A[n]==-1) return 0;
    return 1+F30(A,sz,2*n)+F30(A,sz,2*n+1);
}
```
<div>
<h>Ответ на 30 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 31
```bash
int F31(int A[],int sz, int n) {
    if (n>=sz || A[n]==-1) return 0;
    return A[n]+F31(A,sz,2*n)+F31(A,sz,2*n+1);
}
```
<div>
<h>Ответ на 31 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 32
```bash
int F32(int A[],int sz, int n) {
    if (n>=sz || A[n]==-1) return 0;
    int xx,vv=A[n];
    if ((xx=F32(A,sz,2*n))>vv) vv=xx;
    if ((xx=F32(A,sz,2*n+1))>vv) vv=xx;
    return vv;
}
```
<div>
<h>Ответ на 32 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 33
```bash
int F33(int A[],int sz, int n) {
    if (n>=sz || A[n]==-1) return 0;
    int x1=F33(A,sz,2*n);
    int x2=F33(A,sz,2*n+1);
    return x1>x2 ? x1+1 : x2+1;
}
```
<div>
<h>Ответ на 33 вопрос</h>
<p></p>
</div>

