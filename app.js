let WonikConnect4 = require("./build/Release/wc4.node")
let Gameplay = require("./game.js")


let game = new Gameplay();

game.generateBoard(7, 6)

function winAssert(input){
    switch (input){
        case 200:
            console.log("\n")
            console.log("O has won")
            process.exit()
            
        
        case -200:
            console.log("\n")
            console.log("X has won")
            process.exit()
            

        case 0:
            console.log("\n")
            console.log("Draw")
            process.exit()
    }
}

function run(){
    let aiMove1 = WonikConnect4.ai(game.board, true, 8)
    game.makeMove(1, aiMove1)
    
    console.clear()
    game.printBoard()

    winAssert(WonikConnect4.winCheck(game.board))

    let aiMove2 = WonikConnect4.ai(game.board, false, 8)
    game.makeMove(2, aiMove2)

    console.clear()
    game.printBoard()

    winAssert(WonikConnect4.winCheck(game.board))

    run()
}

game.printBoard()
run();