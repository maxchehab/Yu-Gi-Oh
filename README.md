# 🎴 Yu Gi Oh! 🎴
Terminal adaptation of Yu Gi Oh.

## ⚡ Before you get going ⚡
Make sure you have installed g++ and make.

If you have the dependencies for this project, pop open a terminal (`ctrl-alt-t` for all you nasty neck-beards) and get ready to copy-pasta some commands.

Download the project:
```bash
$ git clone https://github.com/maxchehab/Yu-Gi-Oh.git
$ cd Yu-Gi-Oh
```

To build the executable just...
```bash
$ make
```
To run the game just...
```bash
$ make run
```

## 📃 Rules 📃
Rules of engangement go as followes:
 1. Players first select their names.
 2. A coin is tossed and the order of the players is dictated.
 3. Players are given 5 cards from a _stack_ of cards.
 4. Players decide which cards to place in their attack and defense _queues_.
 5. Cards are _dequeued_ from _queues_. If attack is greater than the defense of another card, the remaining dammage is delt on the player.
 6. Repeat step 4 and 5 until a player dies.
<p align="center">
  <img src="https://media.giphy.com/media/ArvQVNTOFnMyI/giphy.gif" width="450px" />
</p>

