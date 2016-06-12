import pycurl
import StringIO
import json

def userComp(x, y):
    if(x['rating'] == y['rating']):
        return 0
    elif(x['rating'] > y['rating']):
        return -1
    else:
        return 1

def getMultiUserRank(userList):
    c = pycurl.Curl()
    users = ''
    for i in range(0, len(userList)):
        if(i == len(userList) - 1):
            users = users + userList[i]
        else:
            users = users + userList[i] + ';'
    c.setopt(pycurl.URL, 'http://codeforces.com/api/user.info?handles=%s' % users)
    f = StringIO.StringIO()
    c.setopt(pycurl.WRITEFUNCTION, f.write)
    c.perform()
    print f.getvalue()
    result =  json.loads(f.getvalue())['result']
    result = sorted(result, userComp)
    return result

getMultiUserRank(['Ceva', 'xiaodao'])

