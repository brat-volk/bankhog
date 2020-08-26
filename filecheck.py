import os
ext = ".txt"
appdata = os.getenv('APPDATA')
statuspath = appdata
statuspath += "\\myprogram\\files\\status.txt" 
sidpath = appdata
sidpath += "\\myprogram\\files\\sid.txt" 
f = open(sidpath,"r")
sidval = f.read()
pathtobal = appdata
pathtobal += "\\myprogram\\files\\users\\balance\\"
pathtobal += sidval
pathtobal += ext
pathtobal.join(ext)
exists = os.path.isfile(pathtobal)
f2 = open(statuspath,"w+")
f2.truncate(0)
print(exists,file = f2)
exit()