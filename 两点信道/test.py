import random

a_str = 'abcdefghijklmnopq'  # 3 char one time
piece_str = ''  # b:'abc'  bad:0 resend:2 a:  ack:1    bad:0    resend:2
b_str = ''
packet_num = 0
jam = 0
resend = 0
last = 0


def connect_init():
    print("a:Please choose the most suitable velocity.")
    print("b:1kb/s!")


def load_str(packet_n, a, piece_s):
    n = packet_n*3
    piece_s = a[n-3:n]
    print(piece_s)
    return len(piece_s), piece_s


def error_op():
    global piece_str
    temp = random.randint(1, 1000)
    if temp <= 100:
        piece_str = 0
        print('error')


def jam_op():
    temp = random.randint(1, 1000)
    if temp <= 1:
        return 1
    else:
        return 0


def a_judge():
    global jam, packet_num, piece_str, resend
    if(jam == 1):
        return 1
    if(piece_str == 2):
        return 1
    if(piece_str == 1):
        packet_num += 1
        return 1
    if(piece_str == 0):
        resend = 1
        return 1
    packet_num += 1
    return 1


def b_judge():
    global piece_str,  b_str, last
    if(piece_str == 0):
        piece_str = 2
        last = 2
        return 1
    if(piece_str == 2):
        piece_str = last
        return 1
    b_str += piece_str
    piece_str = 1
    last = 1
    return 1


connect_init()
while(1):
    a_judge()
    load, piece_str = load_str(packet_num, a_str, piece_str)
    if(load == 0):
        break
    if(resend == 1):
        piece_str = 2
        resend = 0
    #print('a')
    error_op()
    jam = jam_op()
    if(jam == 1):
        print("jam happened!A don`t receive the reply of B.\nAfter a while.A will resend.")
        continue
    b_judge()
    #print('b')
    error_op()
print('sent over!')
print('B receive '+b_str)
