const express =     require('express');
const app =     express();
const path =    require('path');

app.use(express.urlencoded({extended:true}))

app.use(express.json());
app.use(express.static("./fron"));
app.get('/',
    (req,res) => {
        res.sendFile(path.join(__dirname, "./fron/index.html"))
    }
)


app.get('/win', (req,res)=>{
    res.send({win})
}
)

let win = 0;

app.post('/win',(req,res)=>{
    const {winner} = req.body;
    win = winner;
})

app.listen(5500,()=>{
    console.log('http://127.0.0.1:5500')
})