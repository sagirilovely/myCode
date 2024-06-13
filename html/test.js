const jsonData = {
    id: 1,
    status: 'OK',
    data: [123, 456]
};


function a(){
    console.log(id);
     var { id, status, data } = jsonData;
}

a()