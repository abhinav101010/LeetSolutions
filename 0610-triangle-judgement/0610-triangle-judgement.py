class Solution:
    def triangle_judgement(self, triangles):
        out=[]
        for t in triangles:
            x,y,z=t['x'],t['y'],t['z']
            ok = x+y>z and x+z>y and y+z>x
            out.append([x,y,z,'Yes' if ok else 'No'])
        return out
