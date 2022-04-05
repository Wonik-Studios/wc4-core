const { read } = require("fs");
let WonikConnect4 = require("./build/Release/addon.node")
let Gameplay = require("./game.js")

const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
  });

let game = new Gameplay();

game.generateBoard(7, 6)

/*
let board = [
    [0, 1, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0, 0]
]



game.makeMove(1, 1)
game.makeMove(1, 1)
game.makeMove(1, 1)
game.makeMove(1, 1)
game.makeMove(1, 1)
game.makeMove(1, 1)

game.printBoard(game.board)
*/

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

/*

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

console.log("You are X\n")
game.makeMove(1, WonikConnect4.ai(game.board, true))

game.printBoard()
basicPrompt()

*/


let sleep = ms => new Promise(res => setTimeout(res, ms))

async function main(){
    while (true){
        game.makeMove(1, WonikConnect4.ai(game.board, true))
        game.printBoard()
        winAssert(WonikConnect4.winCheck(game.board))
        await sleep(500)

        game.makeMove(2, WonikConnect4.ai(game.board, false))
        game.printBoard()
        winAssert(WonikConnect4.winCheck(game.board))
        await sleep(500)
    }
}

main()