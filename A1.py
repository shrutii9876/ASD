def tele_data():
    phdata=[];
    n=int(input("\nEnter no. of clients:"))
    print("\nEnter phone no.:")
    for _ in range(n):
        x=int(input("-->"))
        phdata.append(x)
    return phdata

def hf1(key_ele,m_size):
    h1=key_ele%m_size
    return h1

def hf2(key_ele):
    h2=1+(key_ele%11)
    return h2

def hash_table(ht):
    print("Hash value\tKey")
    for ele in range (len(ht)):
        if ht[ele]!=-1:
            print(f"\n{ele}\t-->{ht[ele]}")
        else:
            print(f"\n{ele}")

phn_data=tele_data()
m=int(input("\nEnter hash table size:"))
hashtable=[-1]*m

opt=int(input("\n1.Linear Probing 2.Double Hashing"))

for k in phn_data:
    h1=hf1(k,m)
    h2=hf2(k)
    if(hashtable[h1]==-1):
        hashtable[h1]=k
    else:
        if(opt==1):
            while(hashtable[h1]!=-1):
                h1+=1
            hashtable[h1]=k
        elif(opt==2):
            i=0;
            while(hashtable[h1]!=-1):
                i+=1
                h1=(h1+(i*h2))%m
            hashtable[h1]=k

hash_table(hashtable)
        

