




def add(ins):
    ins = ins.split(" ")[1]
    ins = ins.replace("r","")
    ins = ins.split(",")

    reg1 = bin(int(ins[0])).replace("0b","")
    while(len(reg1)<3):
        reg1 = "0"+reg1

    reg2 = bin(int(ins[1])).replace("0b","")
    while(len(reg2)<3):
        reg2 = "0"+reg2

    reg3 = bin(int(ins[2])).replace("0b","")
    while(len(reg3)<3):
        reg3 = "0"+reg3

    st = "000"+reg1+reg2+"0000"+reg3
    # st = "000" +  bin(int(ins[0])).replace("0b","") + bin(int(ins[1])).replace("0b","") + "0000" + bin(int(ins[2])).replace("0b","")
    print(st)

def addi(ins):
    ins = ins.split(" ")[1]
    ins = ins.replace("r","")
    ins = ins.split(",")
    reg1 = bin(int(ins[0])).replace("0b","")
    while(len(reg1)<3):
        reg1 = "0"+reg1

    reg2 = bin(int(ins[1])).replace("0b","")
    while(len(reg2)<3):
        reg2 = "0"+reg2

    binum = ""
    num = int(ins[2])
    if num<0:
        binum = bin(num).replace("-0b","")
        while(len(binum)<6):
            binum = "0"+binum
        binum = "1"+binum
    else:
        binum = bin(num).replace("0b","")
        while(len(binum)<7):
            binum = "0"+binum

    st = "001"+reg1+reg2+binum
    print(st)

def nand(ins):
    ins = ins.split(" ")[1]
    ins = ins.replace("r","")
    ins = ins.split(",")

    reg1 = bin(int(ins[0])).replace("0b","")
    while(len(reg1)<3):
        reg1 = "0"+reg1

    reg2 = bin(int(ins[1])).replace("0b","")
    while(len(reg2)<3):
        reg2 = "0"+reg2

    reg3 = bin(int(ins[2])).replace("0b","")
    while(len(reg3)<3):
        reg3 = "0"+reg3

    st = "010"+reg1+reg2+"0000"+reg3
    print(st)

def lui(ins):
    ins = ins.split(" ")[1]
    ins = ins.replace("r","")
    ins = ins.split(",")

    reg1 = bin(int(ins[0])).replace("0b","")
    while(len(reg1)<3):
        reg1 = "0"+reg1

    imm = bin(int(ins[1])).replace("0b","")
    while(len(imm)<10):
        imm = "0"+imm

    st = "011"+reg1+imm
    print(st)

def sw(ins):
    ins = ins.split(" ")[1]
    ins = ins.replace("r","")
    ins = ins.split(",")

    reg1 = bin(int(ins[0])).replace("0b","")
    while(len(reg1)<3):
        reg1 = "0"+reg1
    reg2 = bin(int(ins[1])).replace("0b","")
    while(len(reg2)<3):
        reg2 = "0"+reg2

    num = int(ins[2])
    if num<0:
        binum = bin(num).replace("-0b","")
        while(len(binum)<6):
            binum = "0"+binum
        binum = "1"+binum
    else:
        binum = bin(num).replace("0b","")
        while(len(binum)<7):
            binum = "0"+binum
    st = "100"+reg1+reg2+binum
    print(st)

def lw(ins):
    ins = ins.split(" ")[1]
    ins = ins.replace("r","")
    ins = ins.split(",")

    reg1 = bin(int(ins[0])).replace("0b","")
    while(len(reg1)<3):
        reg1 = "0"+reg1
    reg2 = bin(int(ins[1])).replace("0b","")
    while(len(reg2)<3):
        reg2 = "0"+reg2

    num = int(ins[2])
    if num<0:
        binum = bin(num).replace("-0b","")
        while(len(binum)<6):
            binum = "0"+binum
        binum = "1"+binum
    else:
        binum = bin(num).replace("0b","")
        while(len(binum)<7):
            binum = "0"+binum
    st = "101"+reg1+reg2+binum
    print(st)

def beq(ins):
    ins = ins.split(" ")[1]
    ins = ins.replace("r","")
    ins = ins.split(",")

    reg1 = bin(int(ins[0])).replace("0b","")
    while(len(reg1)<3):
        reg1 = "0"+reg1
    reg2 = bin(int(ins[1])).replace("0b","")
    while(len(reg2)<3):
        reg2 = "0"+reg2

    num = int(ins[2])
    if num<0:
        binum = bin(num).replace("-0b","")
        while(len(binum)<6):
            binum = "0"+binum
        binum = "1"+binum
    else:
        binum = bin(num).replace("0b","")
        while(len(binum)<7):
            binum = "0"+binum
    st = "110"+reg1+reg2+binum
    print(st)

def jalr(ins):
    ins = ins.split(" ")[1]
    ins = ins.replace("r","")
    ins = ins.split(",")

    reg1 = bin(int(ins[0])).replace("0b","")
    while(len(reg1)<3):
        reg1 = "0"+reg1
    reg2 = bin(int(ins[1])).replace("0b","")
    while(len(reg2)<3):
        reg2 = "0"+reg2


    st = "111"+reg1+reg2+"0000000"
    print(st)





if __name__ == '__main__':
    while(True):
        asm = input()

        if asm.startswith("addi"):
            addi(asm)

        elif asm.startswith("add"):
            add(asm)
        elif asm.startswith("nand"):
            nand(asm)
        elif asm.startswith("lui"):
            lui(asm)
        elif asm.startswith("sw"):
            sw(asm)
        elif asm.startswith("lw"):
            lw(asm)
        elif asm.startswith("beq"):
            bew(asm)
        elif asm.startswith("jalr"):
            jalr(asm)
