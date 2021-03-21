base=/home/gabriel/Desktop/qd/projetos/libft
caminho=$base/teste
rm -rf -- $caminho
cp -r -v -n $base/libft/ $caminho

if [ "$1" = "1" ]
then
    cd $caminho
    $caminho/change.sh
    cd $2
elif [ "$1" = "2" ]
then
    cd $caminho
    $caminho/change.sh
    cd $2
elif [ "$1" = "3" ]
then
    cd $caminho
    $caminho/change.sh
    cd $2
elif [ "$1" = "4" ]
then
    cd $caminho
    $caminho/change.sh
    cd $2
elif [ "$1" = "5" ]
then
    cd $caminho
    $caminho/change.sh
    cd $2
else
    echo so existem 3 testadores carai
fi

