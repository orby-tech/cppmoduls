const addon = require('./build/Release/addon');

for( let i = 0; i < 1000; i++ ){
    console.log(addon.pi(i));
}
