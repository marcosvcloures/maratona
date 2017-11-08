s=raw_input()
m=int(raw_input())
p=map(int,raw_input().split())
n=len(s)
#befp[i]=max {j: j<i and p[j]=p[i]}
last=[-1]*27
befp=[-1]*m
for i in range(m):
    ch=p[i]
    befp[i]=last[ch]
    last[ch]=i
#befs[i]=max {j: j<i and s[j]=s[i]}
last=[-1]*27
befs=[-1]*n
for i in range(n):
    ch=ord(s[i])-ord('a')
    befs[i]=last[ch]
    last[ch]=i
#f[i]=failure function
f=[0]*m
idx=0
for i in range(1,m):
    match=False
    while idx>0 and not match:
        match=True
        if befp[i]!=-1 and idx>=(i-befp[i]):
            at=idx-(i-befp[i])
            if p[idx]!=p[at]:
                idx=f[idx-1]
                match=False
        if match and befp[idx]!=-1:
            at=i-(idx-befp[idx])
            if p[at]!=p[i]: 
                idx=f[idx-1]
                match=False
    idx+=1
    f[i]=idx
#kmp
idx=0
ans=0
for i in range(n):
    match=False
    while idx>0 and not match:
        match=True
        if befs[i]!=-1 and idx>=(i-befs[i]):
            at=idx-(i-befs[i])
            if p[idx]!=p[at]:
                idx=f[idx-1]
                match=False
        if match and befp[idx]!=-1:
            at=i-(idx-befp[idx])
            if s[at]!=s[i]: 
                idx=f[idx-1]
                match=False           
    idx+=1
    if idx==m: 
        #match at i-m+1
        ans+=1
        idx=f[m-1]
print ans