const socket=io();


socket.on('temp',(data)=>{
    let a=document.getElementById('temp');
    a.innerHTML=`${data} °C`;
});