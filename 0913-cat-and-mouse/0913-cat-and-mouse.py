from functools import lru_cache

class Solution:
    def catMouseGame(self, graph: list[list[int]]) -> int:
        n = len(graph)
        DRAW = 0
        MOUSE = 1
        CAT = 2
        @lru_cache(None)
        def dfs(mouse, cat, turn):
            if mouse == 0:
                return MOUSE
            if cat == mouse:
                return CAT
            if turn == 0:  # mouse turn
                # if any move leads to mouse win, then mouse can win
                best = CAT  # assume cat win
                for nxt in graph[mouse]:
                    res = dfs(nxt, cat, 1)
                    if res == MOUSE:
                        return MOUSE
                    if res == DRAW:
                        best = DRAW
                    # if res == CAT, keep best as CAT unless we have draw
                return best
            else:  # cat turn
                worst = MOUSE  # assume mouse win
                for nxt in graph[cat]:
                    if nxt == 0:  # cat cannot go to hole
                        continue
                    res = dfs(mouse, nxt, 0)
                    if res == CAT:
                        return CAT
                    if res == DRAW:
                        worst = DRAW
                    # if res == MOUSE, keep worst as MOUSE unless we have draw
                return worst
        return dfs(1, 2, 0)
