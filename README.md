# QUARTO
Játékszabályok:
A tábla 4×4 egyforma mezőből áll.

Az összesen 16 figura mindegyike különbözik valamiben a többitől. A figurák négy szempont alapján is két egyforma csoportra oszthatók:

-Magas vagy alacsony

-Sötét vagy világos

-Kerek vagy szögletes

-A teteje lyukas vagy sima.

A figurák mindkét játékos által használhatóak, nincsenek a játékosok között szétosztva.
Kezdéskor a tábla üres.
Az álltalunk létrehozott programban első lépésben mindig a számítógép mondja meg, hogy milyen bábuval kezdhetünk.
Ezután a játékosok felváltva lépnek. A soron következő játékos az ellenfele által kijelölt figurával köteles lépni, azt a tábla valamelyik szabad mezőjére 
kell tennie. Ütés a játékban nincs. A lépés megtétele után ő jelöli ki, hogy az ellenfele melyik figurával lépjen.
A figura kijelölése a játék lényeges eleme, és nem bírálható felül. 
A játékosok felváltva következnek, a játék végéig.
A mi esetünkben amikor a számítógép mondja meg, hogy milyen bábuval lépjünk, akkor első sorban megkell adjuk
a kiválasztott pozició sorát majd oszlopát. A bábu elhelyezése után rajtunk a sor, hogy megmondjuk a számítógépnek, hogy
melyik bábuval lépjen, ilyenkor láthatóak a még szabad bábuk és ezek sorszámát megadva választhatjuk ki őket a szémítógépnek.

A győzelemhez a következő szükséges: 

-A tábla egyenesen, keresztben vagy átlósan négy egyvonalban levő mezőjén négy olyan figurának kell állnia, 
amelyek a felsorolt négy jellemző valamelyikét nézve egy csoportba tartoznak (például négy szögletes figura). 

-Amelyik játékos a lépésével ezt a helyzetet létrehozta, az nyerte a partit.

A bábuk a mi esetünkben 4 betüből álló stringek, ahol:

-Az első betű jelöli, hogy a bábú fehér vagy barna. (F-B)

-A második betű jelöli, hogy kocka vagy henger alakú. (K-H)

-A harmadik jelöli, hogy magas vagy alacsony. (M-A)

-A negyedik pedig, hogy a bábú telített vagy üres. (T-U)

MEGOLDÁSI LOGIKA

A számítógép mindig a lehető legkedvezőbb pozíciót keresi meg a neki adott bábunak a maxgep függvénnyel,
és ez úgy lett megvalósítva, hogy minden bábút kipróbál minden helyre, mindegyik esetben arányt számól abból,
hogy az aktuális pozicíóra hány esetben érdemes odatenni a bábút (mivel lehet hogy az a pozíció győzelmet hozhat vízszintes,
de akár függőleges vagy átlós esetben is, és ezeket figyelni kell mind a négy tulajdonságra) és hogy még hány bábuval kell azt kiegészíteni a sort vagy oszlopot.
A legkisebb arányt kapott pozíció lesz a legmegfelelőbb, és innen tovább lehet bontani a fát.

Fordított esetben viszont mindig a legrosszabb számadatokkal rendelkező bábut adja a számítógép a 
játékosnak.

A futtatáskor megadjuk paraméterként a mélységet és utána a másodpercet.

Példa futtatás: ./minmax.cpp 1 2

Használt környezet: Microsoft Visual Studio 2019

Készítették: 
Gábor-Lukács Zoltán,
Vaszi Imre-Roland
