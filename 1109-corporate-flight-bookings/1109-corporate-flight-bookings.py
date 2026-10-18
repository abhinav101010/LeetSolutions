class Solution:
    def corpFlightBookings(self, bookings, n):
        diff=[0]*(n+2)
        for f,l,s in bookings:
            diff[f]+=s; diff[l+1]-=s
        res=[]; cur=0
        for i in range(1,n+1):
            cur+=diff[i]; res.append(cur)
        return res
