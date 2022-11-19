struct node{
  // node tiap tree tergantung kebutuhan
};
 
template<int MAXN, typename T>
struct segtree {
  vector<T>t;
  segtree() {
    t.assign(MAXN * 4, 2e9);
  }
 
  T comb(T x, T y) {
    // combinasi tergantung kebutuhan
  }
 
  void build(int v, int l, int r) {
    if(l == r) {
      t[v] = ar[l];
    } else {
      int mid = (l + r) >> 1;
      build(v << 1, l, mid);
      build(v << 1 | 1, mid + 1 ,r);
      t[v] = comb(t[v << 1], t[v << 1 | 1]);
    }
  }
 
  void update(int v, int l, int r, int pos, T val) {
    if(l == r && l == pos) {
      t[v] = val;
    } else {
      int mid = (l + r) >> 1;
      if(pos <= mid)
        update(v << 1, l, mid, pos, val);
      else
        update(v << 1 | 1, mid + 1, r, pos, val);
      t[v] = comb(t[v << 1], t[v << 1 | 1]);
    }
  }
 
  T get(int v, int l, int r, int lq, int rq) {
    if(r < lq || l > rq || l > r) {
      return inf;
    }
    if(lq <= l && r <= rq) {
      return t[v];
    }
    int mid = (l + r) >> 1;
    T le = get(v << 1, l, mid, lq, rq);
    T ri = get(v << 1 | 1, mid + 1, r, lq, rq);
    return comb(le,ri);
  }
};
