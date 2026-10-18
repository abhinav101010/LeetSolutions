class Solution:
    def sales_analysis(self, products, sales):
        name = {p['product_id']: p['product_name'] for p in products}
        agg = {}
        for s in sales:
            pid = s['product_id']
            if pid not in agg: agg[pid] = [s['sale_date'], s['sale_date']]
            else:
                agg[pid][0] = min(agg[pid][0], s['sale_date'])
                agg[pid][1] = max(agg[pid][1], s['sale_date'])
        return [[pid, name[pid]] for pid,(mn,mx) in agg.items() if mn >= '2019-01-01' and mx <= '2019-03-31']
