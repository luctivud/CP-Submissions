void solve() {
    int n = ir.readInt();
    long l[] = new long[n];
    long c[] = new long[n];
    HashMap <Long, Long> map[] = new HashMap[n];
    for (int i = 0; i < n; i++)
        l[i] = ir.readLong();
    int m = ir.readInt();
    for (int i = 0; i < n; i++)
        c[i] = ir.readLong();
    for (int i = 0; i < n; i++) {
        map[i] = new HashMap();
        map[i].put(l[i], c[i]);
    }

    for (int i = 1; i < n; i++) {
        long len = l[i];
        long cost = c[i];
        for (int j = 0; j < i; j++) {
            for (long key : map[j].keySet()) {
                long g = gcd(len, key);
                long comp = map[i].get(g) == null ? Long.MAX_VALUE : map[i].get(g);
                map[i].put(g, Math.min(map[j].get(key) + cost, comp) );
            }
        }
    }
    long ans = Long.MAX_VALUE - 1000;
    for (int i = 0; i < n; i++) {
        ans = Math.min(ans, map[i].get(1l) == null ? (Long.MAX_VALUE - 1000) : map[i].get(1l));
    }
    if (ans !=  Long.MAX_VALUE - 1000)
        out.println(ans);
    else
        out.println(-1);

}