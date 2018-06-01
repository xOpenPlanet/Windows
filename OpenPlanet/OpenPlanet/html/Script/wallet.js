function clickFirm()
{
    //var data = document.getElementById("Mnemonic");
   // var jsonData = AccordMnemonicRecovery(data.value);
    //console.log(jsonData);

    var data = document.getElementById("Key");
    var jsonData =  AccordPrivateKeyRecovery(data.value);
    console.log(jsonData);
}

function recoveryFromWord(word)
{
	var json = AccordMnemonicRecovery(word);
	slotRecoveryResult(JSON.stringify(json));
}

function recoveryFromKey(key)
{
    var json = AccordPrivateKeyRecovery(key);
//console.log(json);
    slotRecoveryResult(JSON.stringify(json));
}
