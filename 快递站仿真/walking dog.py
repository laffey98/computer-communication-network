import random


class uestc_dog:
    def __init__(self, retention_rate, proportion_general, choose_rate_general, stock_in, distribute_fee):
        self.retention_rate = retention_rate  # 滞留率
        self.proportion_general = proportion_general  # 普通货物比例（种类比例）
        self.choose_rate_general = choose_rate_general  # 普通服务选择率（服务选择率）
        self.stock_in = stock_in  # 入库量
        self.distribute_fee = distribute_fee  # 配送费

    # 参数
    area = 0
    ppp = 0
    kind = 0
    num = 0
    honeycomb_num = 0
    habit = 0
    retention_time = 7
    capacity_shelf = 0
    capacity_honeycomb = 0
    cost_static = 0
    cost_each = 0
    time_find_shelf = 0
    time_find_honeycomb = 0
    time_list = []
    # shelf 快件数量
    shelf_fresh = 0
    shelf_huge = 0
    shelf_dangerous = 0
    shelf_else = 0
    general = 0
    honeycomb1 = 0
    honeycomb2 = 0
    honeycomb3 = 0
    honeycomb4 = 0
    honeycomb5 = 0
    honeycomb6 = 0
    honeycomb7 = 0
    honeycomb8 = 0
    honeycomb9 = 0
    honeycomb10 = 0
    honeycomb11 = 0
    honeycomb12 = 0
    honeycomb13 = 0
    honeycomb14 = 0
    honeycomb15 = 0
    honeycomb16 = 0
    honeycomb17 = 0
    honeycomb18 = 0
    honeycomb19 = 0
    # parcel
    code = []  # 编码
    time = []  # 停留时间
    # output
    full_honeycomb_first = 0
    full_shelf_first = 0
    profit_month = 0
    time_honeycomb = 0.5
    time_shelf = 0

    def generation(self):  # 快件生成并编号
        a = random.randint(1, 1000)
        if a <= 1000 * self.proportion_general:  # 组团的货物
            self.area = 1
        else:                                  # 非组团的货物
            self.area = 0
        if self.area == 1:  # 1 片区
            b = random.randint(1, 1000)
            if b <= 1000 * self.choose_rate_general:  # 普通货架服务 else
                date = random.randint(1, 7)
                rand_num = random.randint(100, 999)
                rand_code = str(self.area) + str("e") + \
                    str(date) + str(rand_num)
            else:                                  # 蜂巢服务 1——19
                self.num = random.randint(1, 19)
                date = random.randint(1, 7)
                rand_num = random.randint(100, 999)
                if self.num > 10:
                    rand_code = str(self.area) + \
                        str(self.num)+str(date)+str(rand_num)
                else:
                    rand_code = str(self.area) + str(0) + \
                        str(self.num) + str(date) + str(rand_num)
                self.honeycomb_num+=1
        else:     # 0 片区
            self.kind = random.randint(1, 5)
            date = random.randint(1, 7)
            rand_num = random.randint(100, 999)
            if self.kind == 1:  # general
                rand_code = str(self.area) + str("g") + \
                    str(date) + str(rand_num)
            if self.kind == 2:  # fresh
                rand_code = str(self.area) + str("f") + \
                    str(date) + str(rand_num)
            if self.kind == 3:  # huge
                rand_code = str(self.area) + str("h") + \
                    str(date) + str(rand_num)
            if self.kind == 4:  # dangerous
                rand_code = str(self.area) + str("d") + \
                    str(date) + str(rand_num)
            if self.kind == 5:  # else
                rand_code = str(self.area) + str("e") + \
                    str(date) + str(rand_num)
        self.code.append(rand_code)
        self.time.append(1)
        # print(rand_code)

    def into_shelf(self):  # 快件入货架
        if self.area == 1:
            if self.num == 1:
                self.honeycomb1 = self.honeycomb1+1
            if self.num == 2:
                self.honeycomb2 = self.honeycomb2 + 1
            if self.num == 3:
                self.honeycomb3 = self.honeycomb3 + 1
            if self.num == 4:
                self.honeycomb4 = self.honeycomb4 + 1
            if self.num == 5:
                self.honeycomb5 = self.honeycomb5 + 1
            if self.num == 6:
                self.honeycomb6 = self.honeycomb6 + 1
            if self.num == 7:
                self.honeycomb7 = self.honeycomb7 + 1
            if self.num == 8:
                self.honeycomb8 = self.honeycomb8 + 1
            if self.num == 9:
                self.honeycomb9 = self.honeycomb9+1
            if self.num == 10:
                self.honeycomb10 = self.honeycomb10 + 1
            if self.num == 11:
                self.honeycomb11 = self.honeycomb11 + 1
            if self.num == 12:
                self.honeycomb12 = self.honeycomb12 + 1
            if self.num == 13:
                self.honeycomb13 = self.honeycomb13 + 1
            if self.num == 14:
                self.honeycomb14 = self.honeycomb14 + 1
            if self.num == 15:
                self.honeycomb15 = self.honeycomb15 + 1
            if self.num == 16:
                self.honeycomb16 = self.honeycomb16 + 1
            if self.num == 17:
                self.honeycomb17 = self.honeycomb17 + 1
            if self.num == 18:
                self.honeycomb18 = self.honeycomb18 + 1
            if self.num == 19:
                self.honeycomb19 = self.honeycomb19 + 1
        else:
            if self.kind == 1:
                self.general = self.general + 1
            if self.kind == 2:
                self.shelf_fresh = self.shelf_fresh + 1
            if self.kind == 3:
                self.shelf_huge = self.shelf_huge + 1
            if self.kind == 4:
                self.shelf_dangerous = self.shelf_dangerous + 1
            if self.kind == 5:
                self.shelf_else = self.shelf_else + 1

    def store_full_time(self, day):      # 仓满判断并记录

        if self.honeycomb1 >= self.capacity_honeycomb:
            return day
        if self.honeycomb2 >= self.capacity_honeycomb:
            return day
        if self.honeycomb3 >= self.capacity_honeycomb:
            return day
        if self.honeycomb4 >= self.capacity_honeycomb:
            return day
        if self.honeycomb5 >= self.capacity_honeycomb:
            return day
        if self.honeycomb6 >= self.capacity_honeycomb:
            return day
        if self.honeycomb7 >= self.capacity_honeycomb:
            return day
        if self.honeycomb8 >= self.capacity_honeycomb:
            return day
        if self.honeycomb9 >= self.capacity_honeycomb:
            return day
        if self.honeycomb10 >= self.capacity_honeycomb:
            return day
        if self.honeycomb11 >= self.capacity_honeycomb:
            return day
        if self.honeycomb12 >= self.capacity_honeycomb:
            return day
        if self.honeycomb13 >= self.capacity_honeycomb:
            return day
        if self.honeycomb14 >= self.capacity_honeycomb:
            return day
        if self.honeycomb15 >= self.capacity_honeycomb:
            return day
        if self.honeycomb16 >= self.capacity_honeycomb:
            return day
        if self.honeycomb17 >= self.capacity_honeycomb:
            return day
        if self.honeycomb18 >= self.capacity_honeycomb:
            return day
        if self.honeycomb19 >= self.capacity_honeycomb:
            return day
        if self.general >= self.capacity_shelf:
            return day
        if self.shelf_fresh >= self.capacity_shelf:
            return day
        if self.shelf_huge >= self.capacity_shelf:
            return day
        if self.shelf_dangerous >= self.capacity_shelf:
            return day
        if self.shelf_else >= self.capacity_shelf:
            return day

    def out_shelf(self, busy):  # 随机取件busy,total
        #self.time_list = self.out(self,busy)
        li = [0]*5
        people = 0
        time = 100
        shelf = []
        self.ppp = 0
        while time > 0:
            if time > 10:
                if busy == 1:
                    n = random.randint(5, 10)
                else:
                    n = random.randint(0, 5)
            else:
                n = 0
            people += n
            self.ppp += n
            if people < 20:
                m = 1
            elif people < 40:
                m = 2
            elif people < 50:
                m = 3
            elif people < 60:
                m = 4
            else:
                m = 5
            while(n > 0):
                shelf = shelf+[m]
                li[m-1] += 1
                n -= 1
            if(len(shelf) != 0):
                shelf.pop(0)
            people = len(shelf)
            time -= 1
        self.time_list = li
        while self.ppp > 0:
            tatal = len(self.code)-1
            if tatal == -1:
                break
            n = random.randint(0, tatal)
            # shelf--
            del self.code[n]
            del self.time[n]
            self.ppp -= 1

    def out(self, busy):
        li = [0]*5
        people = 0
        time = 100
        shelf = []
        self.ppp = 0
        while time > 0:
            if time > 10:
                if busy == 1:
                    n = random.randint(5, 10)
                else:
                    n = random.randint(0, 5)
            else:
                n = 0
            people += n
            self.ppp += n
            if people < 20:
                m = 1
            elif people < 40:
                m = 2
            elif people < 50:
                m = 3
            elif people < 60:
                m = 4
            else:
                m = 5
            while(n > 0):
                shelf = shelf+[m]
                li[m-1] += 1
                n -= 1
            shelf.pop(0)
            people = len(shelf)
            time -= 1
        return li

    def into_retention(self):  # 快件转滞留
        for i in range(len(self.time)-1):
            if self.time[i] == self.retention_time:
                del self.time[i]
                del self.code[i]

    def profit(self, day):                   # 利润
        equipment_expense = 10835    # 设备成本
        staff_expense = 5000*3          # 员工费用
        distribution_profit = 1.0         # 派件利润#########3参数统一放
        rent = 3000  # 租金
        self.profit_month = distribution_profit*self.stock_in*day + self.distribute_fee * \
            self.honeycomb_num - rent*day/30-staff_expense*day/30-equipment_expense  # 总利润
        # print("---------------------------")
        # print("利润仿真结果:")
        # print("总利润仿真结果:", end="")
        # print(self.profit_month)

    def average_pick_up_time(self):     # 平均取货时间（用户从准备取货到取到货物的时间）
        find_honeycomb_time = 30       # 蜂巢找货时间
        # arrive_honeycomb_time = 120     # 到达蜂巢时间
        honeycomb_time = find_honeycomb_time  # 蜂巢平均取货时间
        time_all = 0
        people_all = 0
        for i in range(len(self.time_list)-1):
            time_all += self.time_list[i]*(i+1)
            people_all += self.time_list[i]
        self.time_shelf = time_all/people_all
        # return honeycomb_time,general_time
        # print("---------------------------")
        # print("平均取货时间仿真结果:")
        # print("蜂巢:", end='')
        # print(honeycomb_time)
        # print("普通货架:", end='')
        # print(self.time_shelf)
        # print("---------------------------")

    def out_put(self):
        print("运行结束，以下是输出...")
        print("每月利润：{}".format(self.profit_month))
        print("蜂巢取件时间：{}".format(self.time_honeycomb))
        print("货架取件时间：{}".format(self.time_shelf))

    def print_shelf(self):
        print(self.shelf_fresh,
              self.shelf_huge,
              self.shelf_dangerous,
              self.shelf_else,
              self.honeycomb1,
              self.honeycomb2,
              self.honeycomb3,
              self.honeycomb4,
              self.honeycomb5,
              self.honeycomb6,
              self.honeycomb7,
              self.honeycomb18,
              self.honeycomb19,
              self.code,
              self.time)


def in_put():  # 读取输入函数
    print("开始初始化程序...")
    retention_rate = float(input("请输入滞留率："))
    proportion_general =float( input("请输入货物比例(货架/总快件)："))
    choose_rate_general = float(input("请输入服务选择率（不选服务/组团的快件）："))
    stock_in = float(input("请输入每天入库量："))
    distribute_fee = float(input("请输入配送费："))
    return retention_rate, proportion_general, choose_rate_general, stock_in, distribute_fee


def main():
    busy = 0
    day = 0
    aaa = 0
    retention_rate = 0
    proportion_general = 0
    choose_rate_general = 0
    stock_in = 0
    distribute_fee = 0
    retention_rate, proportion_general, choose_rate_general, stock_in, distribute_fee = in_put()
    test = uestc_dog(retention_rate, proportion_general,
                     choose_rate_general, stock_in, distribute_fee)
    while day < 101:
        if day % 50 == 0:
            busy = 1
            aaa = int(stock_in)
        else:
            busy = 0
            aaa = int(stock_in)*2
        while aaa>0:
            test.generation()
            test.into_shelf()
            aaa-=1
        test.out_shelf(busy)
        test.into_retention()
        day += 1
    test.average_pick_up_time()
    test.profit(100)
    test.out_put()


main()
