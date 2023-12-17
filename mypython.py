def getServerIndex(n,arrival,burst): 
    res = [] 
    ser = [-1]*(n+1) 
    req = [] 
    for i in range(len(arrival)): 
        req.append([arrival[i],burst[i],i]) 
    req.sort(key=lambda x :x[0]) 
 
    for i in range(len(req)): 
        curr  = req[i] 
        fl = 0 
        for j in range(1,len(ser)): 
            if ser[j]==-1 or ser[j]<=curr[0]: 
                res.append([curr[2]+1,j]) 
                ser[j] = curr[0] + curr[1] 
                fl = 1 
                break 
        if fl==0: 
            res.append([curr[2]+1,-1]) 
     
    res.sort(key=lambda x : x[0]) 
    # print(res) 
 
    ans   = [] 
    for i in res: 
        ans.append(i[1]) 
    return ans

n = 3
arrival = [2, 4, 1, 8, 9]
burstTime = [7, 9, 2, 4, 5]

result = getServerIndex(n, arrival, burstTime)

for i, assigned_server in enumerate(result):
    print(f"Request index {i + 1} assigned to Server {assigned_server}")
