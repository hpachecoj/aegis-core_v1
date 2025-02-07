(function(){
    //Abaixo uma estrutura de dados em Pilha

//Função construtora de elementos para a pilha
function Elemento(nome, id, ordem){
    this.nome = nome
    this.id = id
    this.ordem = ordem
}

var el1 = new Elemento("Cadeira", 123, 10)
var el2 = new Elemento("Mesa", 456, 9)
var el3 = new Elemento("Sapato", 3993, 1)
var el4 = new Elemento("Caneta", 4993, 0)
var el5 = new Elemento("Computador", 4949, 2)
var el6 = new Elemento("Mouse", 388, 4)
var el7 = new Elemento("Sofá", 48833, 8)






class Pilha{ 
    constructor(top = null, count = 0){
        this.top = top
        this.count = count
    }
    //Método contador
    GetContador(){
        return this.count
    }
    //Método para criar o nó
    Push(data){
        let no = {
            data : data,
            next : null
        }
        no.next = this.top;
        this.top = no;
        this.count++;
    }
    //Método para visualizar 
    Visualizar(){
        if(this.top === null){ return null}else{
            return this.top.data;
        }
    }
    //Método para remover
    Remover(){
        if(this.top === null){return null}else{
            let remover = this.top;
            this.top = this.top.next;

            if(this.count > 0){
                this.count--;
            }
            return remover.data;
        }
    }
    //Método para mostrar todos
    MostrarTodos(){
        if(this.top === null){ return null}else{
            let arr = []
            let current = this.top;

            for(let index = 0; index < this.count; index++){
                arr[index] = current.data;
                current = current.next
            }
            return arr;
        }
    }
}

    //Testando a nossa Estrutura de Dados em Pilha
var pilha = new Pilha();
pilha.Push(1);
pilha.Push(2);
pilha.Push(3);
pilha.Push(4);
pilha.Push(5);
pilha.Push(6);
pilha.Push(7);
pilha.Remover();
console.log(pilha.Visualizar());
console.log(pilha.MostrarTodos());
console.log(pilha);
})




//Função construtora que cria diversos tipos de funções
function Conta(value, a, bc){
    this.value = value
    this.a = a
    this.bc = bc
    const random =()=>{
    const random = Math.floor(Math.random()*2)
    if(random){return random}else{
        return 0
    }
   }
    const equacao = value *(a-(bc/Math.E))
    return console.log(`${equacao.toFixed(2)} + ${random()}`)
}

for(let i = 0; i<=10;i++){
    const f = new Conta(12,34,5)
    console.log(f)
}