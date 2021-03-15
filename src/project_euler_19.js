let i = 1;
let y = 1901;
let c = 0;

while (y<2001)
{
    let d = new Date(y,i,1,10,10,10,10);
    if (d.getUTCDay() == 0)
    {
        c+=1;
    }
    i+=1;
    if (i>12)
    {
        i=1;
        y+=1;
    }
}

console.log(c);