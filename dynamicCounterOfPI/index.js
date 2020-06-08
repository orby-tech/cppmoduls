const addon = require('./build/Release/addon');


let last = 0
for( let i = 0; i < 10; i++ ){
    
    console.log(addon.pi(i));
}
