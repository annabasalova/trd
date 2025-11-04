const int k = 26;

struct Vertex {
    Vertex *to[k] = {0}, *go[k] = {0};
    Vertex *link = 0, *p;
    int pch;
    Vertex (int _pch, Vertex *_p) { pch = _pch, p = _p; }
};

Vertex *root = new Vertex(-1, 0);
void add_string(string &s) {
    Vertex *v = root;
    for (char _c : s) {
        int c -= int(_c - 'a');
        if (!v->to[c])
            v->to[c] = new Vertex(c, v);
        v = v->to[c];
    }
}
// нам нужно объявить две функции, ссылающиеся друг на друга
// в C/C++ для этого нужно сигнатуру хотя бы одной из них объявить перед другой
Vertex* go(Vertex *v, int c);

Vertex* link(Vertex *v) {
    if (!v->link) {
        // для строк длины меньше двух суффиксная ссылка это корень
        if (v == root || v->p == root)
            v->link = root;
        else // в остальных случаях формула работает
            v->link = go(link(v->p), v->pch);
    }
    return v->link;
}

Vertex* go(Vertex *v, int c) {
    if (!v->go[c]) {
        // если переход есть, то автоматный должен вести туда же
        if (v->to[c])
            v->go[c] = v->to[c];
        // если перехода нет, но вершина корень, то нужно сделать петлю
        else if (v == root)
            v->go[c] = root;
        else // в остальных случаях формула работает
            v->go[c] = go(link(v), c);
    }
    return v->go[c];
}
