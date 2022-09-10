
def gen_mess(m):
    for i in range(2**m):
        print(bin(i)[2:].zfill(4))

def matmult():
    pass

gen_mess(4)
