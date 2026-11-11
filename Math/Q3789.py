class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        if(cost1+cost2<=costBoth):
            Cost=(cost1*need1)+(cost2*need2)
        else:
            c3=min(need1,need2)
            Cost=c3*costBoth
            need1=need1-c3
            need2=need2-c3
            if(need1>0):
                Cost=Cost+(need1*min(cost1,costBoth))
            elif(need2>0):
                Cost=Cost+(need2*min(cost2,costBoth))
        return Cost
