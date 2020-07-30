# -*- coding: UTF-8 -*-
import subprocess
from flask import Flask, render_template, request
app = Flask(__name__)


class AI:
    def __init__(self, path):
        self.path = path
        self.ison = False

    def send(self, mes):
        val = str(mes) + '\n'
        val = bytes(val, 'UTF-8')
        self.prog.stdin.write(val)
        self.prog.stdin.flush()

    def rec(self):
        return self.prog.stdout.readline().strip().decode()

    def init(self, side):
        self.prog = subprocess.Popen(self.path,
                                    stdin=subprocess.PIPE,
                                    stdout=subprocess.PIPE)
        self.send(2-side)
        self.ison = True
        if (side == 2):
            self.action(-1, -1)

    def action(self, r, c):
        self.send(str(r) + ' ' + str(c))
        val = self.rec().split(' ')
        return int(val[0]), int(val[1])

    def end(self):
        if (self.ison):
            self.prog.terminate()
            self.ison = False


ai0 = AI("./GobangAI")


@app.route('/')
def initialize():
    return render_template('Gobang.html')


@app.route('/initialize', methods=['POST'])
def start_pro():
    tmp_data = int(request.get_data())
    ai0.end()
    ai0.init(tmp_data)
    return 'Successfully run the AI!'


@app.route('/action', methods=['POST'])
def get_action():
    tmp_data = request.get_data().decode().split(' ')
    r, c = ai0.action(int(tmp_data[0]), int(tmp_data[1]))
    print("玩家落子: "+'['+tmp_data[0]+", "+tmp_data[1]+']')
    tmp_val = {'row': r, 'col': c}
    print("AI落子: "+'['+str(r)+", "+str(c)+']')
    return tmp_val


if __name__ == '__main__':
    app.run(debug=True)
