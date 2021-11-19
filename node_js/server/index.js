/*Configuracion index
npm install nodemon --save
npm init --yes

configurar el start para iniciar

npm start


*/

/*Servidor se utiliza express se puede utilizar mas framework
npm i install express
*/
const express = require ('express');
const app= express();
/*Enviar datos en tiempo real socket.io
npm i socket.io
*/
const socketIo=require('socket.io');
const http = require('http');
const server= http.createServer(app);
const io=socketIo.listen(server);

/*Configuracion de conexion de puertos
npm install serialport
 */
const SerialPort = require('serialport');
const Readline=SerialPort.parsers.Readline;
const parser= new Readline();
const mySerial =new SerialPort('COM10',{
	baudRate: 9600
});

/*Eventlistener*/
mySerial.on('open',function(){
	console.log('Puerto  Serial abierto');
});
/*Manejo de Datos*/
mySerial.on('data',function(data){
	console.log(data);
});

/*
io.emit('arduino:data',{
	value:data.toString()
});
});

/*Manejo de errores*/
mySerial.on('err',function(){
	console.log(err.message);
});

/*Hacemos que el servidor escuche las peticiones*/

server.listen(2000,()=>{
	console.log('server on port',2000);
});

/*mostar el html en la pagina inicial*/

app.get('/',(req,res,next)=>{
	res.sendFile(__dirname+'/index.html')
});

/* */
io.on('connection', function (data){
console.log('a new socket con')
});
