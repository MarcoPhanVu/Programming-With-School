curr_index = 260
prev_index = 50
total_price = 0

levels = [1.678, 2, 3, 4, 5, 6] #tu fill

level = int(260 / 50)

for i in range level: #i -> i = level:
    total_price += levels[i] * 50
#xong cai loop
#gio tinh cai du

total_price += levels[level]*(curr_index - prev_index - level*50)

print(total_price)