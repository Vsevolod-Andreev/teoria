import java.util.*
import kotlin.collections.ArrayList
import kotlin.collections.HashMap
import java.io.File

fun readCOW(path: String): MutableList<String> {
    var arr: MutableList<String> = mutableListOf()
    val ops = arrayOf("moo","MOO","moO","mOo","MoO","MOo","Moo","OOM")
    val file = File(path)
    for (line in file.readLines()){
        for(word in line.split(" "))
            if(word.isNotEmpty())
                if (word in ops)
                    arr.add(word)
    }
    return arr
}

fun getLoopBlocks(source: MutableList<String>): HashMap<Int, Int>{ 
    val blocks = HashMap<Int, Int>()
    val stack = mutableListOf<Int>()
    for ((i, char) in source.withIndex()){
        if (char == "MOO"){
            stack.add(i)
        }
        if (char == "moo"){
            blocks[i] = stack[stack.lastIndex]
            blocks[stack.removeAt(stack.lastIndex)] = i
        }
    }
    return blocks
}

fun eval(source: MutableList<String>){
    val buffer = Array<Char> (200){ _ -> (0).toChar()}
    var ptr = 0 
    val blocks = getLoopBlocks(source)
    var i = 0 
    while (i < source.size ){
        when (source[i].toString()) {
            "moO" ->ptr += 1
            "mOo" -> ptr -= 1
            "MoO" -> buffer[ptr] = buffer[ptr] + 1
            "MOo" -> buffer[ptr] = buffer[ptr] - 1
            "OOM" -> print(buffer[ptr].toInt())
            "Moo" -> {
                if (buffer[ptr] == (0).toChar()) {
                    print(">>")
                    buffer[ptr] = readLine()?.toCharArray()?.get(0)!!
                } else {
                    print(buffer[ptr])
                }
            }
            "MOO" ->{
                if (buffer[ptr] == (0).toChar()){
                    i = blocks[i]!!
                }
            }
            "moo" ->{
                if (buffer[ptr] != (0).toChar()){
                    i = blocks[i]!!
                }
            }
        }
        i += 1
    }
}

fun main(args: Array<String>){
    val source = readCOW("fib.cow")
    eval(source)
}
