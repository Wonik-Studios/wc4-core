let WonikConnect4 = require("./build/Release/wc4.node")
let Gameplay = require("./game.js")

const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
  });

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



function basicPrompt(){
    readline.question("Column Index:", ans => {
        console.log("\n")
        game.makeMove(2, Number(ans) - 1)
        game.printBoard()
        winAssert(WonikConnect4.winCheck(game.board))
        
        console.log("\n")
        game.makeMove(1, WonikConnect4.ai(game.board, true))
        game.printBoard()
        winAssert(WonikConnect4.winCheck(game.board))

        basicPrompt()
    })
}

console.log("You are O\n")
//game.makeMove(1, WonikConnect4.ai(game.board, true))

game.printBoard()
basicPrompt()
