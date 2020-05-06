.class public Lru/nechta/lab3/two;
.super Landroid/app/Activity;
.source "two.java"


# static fields
.field public static Num:I


# instance fields
.field ic:[I

.field n:[Ljava/lang/String;


# direct methods
.method static constructor <clinit>()V
    .locals 1

    .prologue
    .line 10
    const/4 v0, 0x3

    sput v0, Lru/nechta/lab3/two;->Num:I

    return-void
.end method

.method public constructor <init>()V
    .locals 4

    .prologue
    const/4 v3, 0x5

    .line 9
    invoke-direct {p0}, Landroid/app/Activity;-><init>()V

    .line 11
    new-array v0, v3, [Ljava/lang/String;

    const/4 v1, 0x0

    const-string v2, "Linux"

    aput-object v2, v0, v1

    const/4 v1, 0x1

    const-string v2, "Dos"

    aput-object v2, v0, v1

    const/4 v1, 0x2

    const-string v2, "Windows 3.11"

    aput-object v2, v0, v1

    const/4 v1, 0x3

    const-string v2, "Windows XP"

    aput-object v2, v0, v1

    const/4 v1, 0x4

    const-string v2, "Android"

    aput-object v2, v0, v1

    iput-object v0, p0, Lru/nechta/lab3/two;->n:[Ljava/lang/String;

    .line 12
    new-array v0, v3, [I

    fill-array-data v0, :array_0

    iput-object v0, p0, Lru/nechta/lab3/two;->ic:[I

    return-void

    nop

    :array_0
    .array-data 4
        0x7f020008
        0x7f020007
        0x7f020007
        0x7f020008
        0x7f020005
    .end array-data
.end method


# virtual methods
.method public onCreate(Landroid/os/Bundle;)V
    .locals 4
    .param p1, "savedInstanceState"    # Landroid/os/Bundle;

    .prologue
    .line 15
    invoke-super {p0, p1}, Landroid/app/Activity;->onCreate(Landroid/os/Bundle;)V

    .line 16
    const v2, 0x7f030004

    invoke-virtual {p0, v2}, Lru/nechta/lab3/two;->setContentView(I)V

    .line 17
    const v2, 0x7f050003

    invoke-virtual {p0, v2}, Lru/nechta/lab3/two;->findViewById(I)Landroid/view/View;

    move-result-object v1

    check-cast v1, Landroid/widget/ListView;

    .line 18
    .local v1, "l":Landroid/widget/ListView;
    new-instance v0, Lru/nechta/lab3/MyAdapter;

    iget-object v2, p0, Lru/nechta/lab3/two;->n:[Ljava/lang/String;

    iget-object v3, p0, Lru/nechta/lab3/two;->ic:[I

    invoke-direct {v0, p0, v2, v3}, Lru/nechta/lab3/MyAdapter;-><init>(Landroid/content/Context;[Ljava/lang/String;[I)V

    .line 19
    .local v0, "a":Lru/nechta/lab3/MyAdapter;
    invoke-virtual {v1, v0}, Landroid/widget/ListView;->setAdapter(Landroid/widget/ListAdapter;)V

    .line 21
    return-void
.end method
