## Ответы на вопросы к лабе2
# //------------------------------------------------------- 0
struct list { int val; list *next,*prev; };
# //------------------------------------------------------- 1
```bash
int F1(list *p)
{
    int n;
    for (n = 0; p != NULL; p = p->next, n++);
    return n;
}
```
<div>
<h>Ответ на 1 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 2
```bash
list *F2(list *ph, int v)
{
    list *q = new list;
    q->val = v;
    q->next = ph;
    ph = q;
    return ph;
}
```
<div>
<h>Ответ на 2 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 3
```bash
list *F3(list *p, int n)
{
    for (; n != 0 && p != NULL; n--, p = p->next);
    return p;
}
```
<div>
<h>Ответ на 3 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 4
```bash
list *F4(list *ph, int v)
{
    list *p, *q = new list;
    q->val = v;
    q->next = NULL;
    if (ph == NULL) return q;
    for (p = ph; p->next != NULL; p = p->next);
    p->next = q;
    return ph;
}
```
<div>
<h>Ответ на 4 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 5
```bash
list *F5(list *ph, int n)
{
    list *q, *pr, *p;
    for (p = ph, pr = NULL; n != 0 && p != NULL; n--, pr = p, p = p->next);
    // © Романов Е.Л. Беседы о программировании 13.
    if (p == NULL) return ph;
    if (pr == NULL) {
        q = ph;
        ph = ph->next;
    } else {
        q = p;
        pr->next = p->next;
    }
    delete q;
    return ph;
}
```
<div>
<h>Ответ на 5 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 6
```bash
int F6(list *p)
{
    int n;
    list *q;
    if (p == NULL) return 0;
    for (q = p, p = p->next, n = 1; p != q; p = p->next, n++);
    return n;
}
```
<div>
<h>Ответ на 6 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 7
```bash
list *F7(list *p, int v)
{
    list *q;
    q = new list;
    q->val = v;
    q->next = q->prev = q;
    if (p == NULL) p = q;
    else {
        q->next = p;
        q->prev = p->prev;
        p->prev->next = q;
        p->prev = q;
        p = q;
    }
    return p;
}
```
<div>
<h>Ответ на 7 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 8
```bash
list *F8(list *ph)
{
    list *q, *out, *p, *pr;
    out = NULL;
    while (ph != NULL) {
        q = ph;
        ph = ph->next;
        for (p = out, pr = NULL; p != NULL && q->val > p->val; pr = p, p = p->next);
        if (pr == NULL) {
            q->next = out;
            out = q;
        } else {
            q->next = p;
            pr->next = q;
        }
    }
    return out;
}
```
<div>
<h>Ответ на 8 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 9
```bash
list *F9(list *pp, int n)
{
    list *q;
    for (q = pp; n != 0; q = q->next, n--);
    if (q->next == q) {
        delete q;
        return NULL;
    }
    if (q == pp) pp = q->next;
    q->prev->next = q->next;
    q->next->prev = q->prev;
    delete q;
    return pp;
}
```
<div>
<h>Ответ на 9 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 10
```bash
list *F10(list *ph, int v)
{
    list *q, *pr, *p;
    q = new list;
    q->val = v;
    q->next = NULL;
    if (ph == NULL) return q;
    for (p = ph, pr = NULL; p != NULL && v > p->val; pr = p, p = p->next);
    if (pr == NULL) {
        q->next = ph;
        ph = q;
    } else {
        q->next = p;
        pr->next = q;
    }
    return ph;
}
```
<div>
<h>Ответ на 10 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 11
```bash
list *F11(list *ph, int v)
{
    list *q = new list;
    q->val = v;
    q->next = q->prev = q;
    if (ph == NULL) return q;
    list *p = ph;
    do {
        if (v < p->val) break;
        p = p->next;
    } while (p != ph);
    q->next = p;
    q->prev = p->prev;
    p->prev->next = q;
    p->prev = q;
    if (ph->val > v) ph = q;
    return ph;
}
```
<div>
<h>Ответ на 11 вопрос</h>
<p></p>
</div>

# //------------------------------------------------------- 12
```bash
void F12(list *&ph, int v, int n)
{
    list *q = new list;
    int n0 = n;
    q->val = v;
    q->next = q->prev = q;
    if (ph == NULL) {
        ph = q;
        return;
    }
    list *p;
    for (p = ph; n-- != 0; p = p->next);
    q->next = p;
    q->prev = p->prev;
    p->prev->next = q;
    p->prev = q;
    if (n0 == 0) ph = q;
}ц
```
<div>
<h>Ответ на 12 вопрос</h>
<p></p>
</div>