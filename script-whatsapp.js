const wbm = require('wbm');

wbm.start({showBrowser: false, qrCodeData: false, session: false}).then(async () => {
    const phones = ['5566992332501'];
    const message = 'Ola';
    await wbm.waitQRCode();
    await wbm.send(phones, message);
    await wbm.end();
}).catch(err => console.log(err));
