.class public Lru/nechta/lab3/three;
.super Landroid/app/Activity;
.source "three.java"


# instance fields
.field city:[Ljava/lang/String;

.field png:[I


# direct methods
.method public constructor <init>()V
    .locals 4

    .prologue
    const/4 v3, 0x3

    .line 14
    invoke-direct {p0}, Landroid/app/Activity;-><init>()V

    .line 16
    const/16 v0, 0x8

    new-array v0, v0, [Ljava/lang/String;

    const/4 v1, 0x0

    const-string v2, "\u0422\u043e\u043a\u0438\u043e"

    aput-object v2, v0, v1

    const/4 v1, 0x1

    const-string v2, "\u0422\u0443\u043b\u0430"

    aput-object v2, v0, v1

    const/4 v1, 0x2

    const-string v2, "\u041c\u043e\u0441\u043a\u0432\u0430"

    aput-object v2, v0, v1

    const-string v1, "\u0422\u044e\u043c\u0435\u043d\u044c"

    aput-object v1, v0, v3

    const/4 v1, 0x4

    const-string v2, "\u041f\u0435\u043a\u0438\u043d"

    aput-object v2, v0, v1

    const/4 v1, 0x5

    const-string v2, "\u041a\u0438\u043e\u0442\u043e"

    aput-object v2, v0, v1

    const/4 v1, 0x6

    const-string v2, "\u041d\u043e\u0432\u043e\u0441\u0438\u0431\u0438\u0440\u0441\u043a"

    aput-object v2, v0, v1

    const/4 v1, 0x7

    const-string v2, "\u0414\u0430\u043c\u0430\u0441\u043a"

    aput-object v2, v0, v1

    iput-object v0, p0, Lru/nechta/lab3/three;->city:[Ljava/lang/String;

    .line 17
    new-array v0, v3, [I

    fill-array-data v0, :array_0

    iput-object v0, p0, Lru/nechta/lab3/three;->png:[I

    return-void

    nop

    :array_0
    .array-data 4
        0x7f020003
        0x7f020004
        0x7f02000a
    .end array-data
.end method


# virtual methods
.method makepng(I)Landroid/widget/ImageView;
    .locals 1
    .param p1, "res"    # I

    .prologue
    .line 30
    new-instance v0, Landroid/widget/ImageView;

    invoke-direct {v0, p0}, Landroid/widget/ImageView;-><init>(Landroid/content/Context;)V

    .line 31
    .local v0, "png":Landroid/widget/ImageView;
    invoke-virtual {v0, p1}, Landroid/widget/ImageView;->setImageResource(I)V

    .line 32
    return-object v0
.end method

.method makerow(Ljava/lang/String;)Landroid/widget/TextView;
    .locals 3
    .param p1, "s"    # Ljava/lang/String;

    .prologue
    .line 23
    new-instance v0, Landroid/widget/TextView;

    invoke-direct {v0, p0}, Landroid/widget/TextView;-><init>(Landroid/content/Context;)V

    .line 24
    .local v0, "txt":Landroid/widget/TextView;
    invoke-virtual {v0, p1}, Landroid/widget/TextView;->setText(Ljava/lang/CharSequence;)V

    .line 25
    sget-object v1, Landroid/graphics/Typeface;->SERIF:Landroid/graphics/Typeface;

    const/4 v2, 0x1

    invoke-virtual {v0, v1, v2}, Landroid/widget/TextView;->setTypeface(Landroid/graphics/Typeface;I)V

    .line 26
    const/16 v1, 0x11

    invoke-virtual {v0, v1}, Landroid/widget/TextView;->setGravity(I)V

    .line 27
    return-object v0
.end method

.method protected onCreate(Landroid/os/Bundle;)V
    .locals 11
    .param p1, "savedInstanceState"    # Landroid/os/Bundle;

    .prologue
    const/16 v10, 0x11

    const/4 v7, 0x1

    const/4 v8, 0x0

    .line 37
    invoke-super {p0, p1}, Landroid/app/Activity;->onCreate(Landroid/os/Bundle;)V

    .line 39
    new-instance v3, Landroid/widget/TableLayout;

    invoke-direct {v3, p0}, Landroid/widget/TableLayout;-><init>(Landroid/content/Context;)V

    .line 40
    .local v3, "table":Landroid/widget/TableLayout;
    const/16 v6, 0x9

    new-array v2, v6, [Landroid/widget/TableRow;

    .line 42
    .local v2, "rows":[Landroid/widget/TableRow;
    invoke-virtual {v3, v7}, Landroid/widget/TableLayout;->setShrinkAllColumns(Z)V

    .line 43
    invoke-virtual {v3, v7}, Landroid/widget/TableLayout;->setStretchAllColumns(Z)V

    .line 46
    new-instance v6, Landroid/widget/TableRow;

    invoke-direct {v6, p0}, Landroid/widget/TableRow;-><init>(Landroid/content/Context;)V

    aput-object v6, v2, v8

    .line 47
    aget-object v6, v2, v8

    invoke-virtual {v6, v10}, Landroid/widget/TableRow;->setGravity(I)V

    .line 50
    aget-object v6, v2, v8

    const-string v7, "\u0413\u043e\u0440\u043e\u0434"

    invoke-virtual {p0, v7}, Lru/nechta/lab3/three;->makerow(Ljava/lang/String;)Landroid/widget/TextView;

    move-result-object v7

    invoke-virtual {v6, v7}, Landroid/widget/TableRow;->addView(Landroid/view/View;)V

    .line 51
    new-instance v1, Landroid/widget/TableRow$LayoutParams;

    invoke-direct {v1}, Landroid/widget/TableRow$LayoutParams;-><init>()V

    .line 52
    .local v1, "p":Landroid/widget/TableRow$LayoutParams;
    const/4 v6, 0x2

    iput v6, v1, Landroid/widget/TableRow$LayoutParams;->span:I

    .line 53
    aget-object v6, v2, v8

    const-string v7, "\u041f\u043e\u0433\u043e\u0434\u0430"

    invoke-virtual {p0, v7}, Lru/nechta/lab3/three;->makerow(Ljava/lang/String;)Landroid/widget/TextView;

    move-result-object v7

    invoke-virtual {v6, v7, v1}, Landroid/widget/TableRow;->addView(Landroid/view/View;Landroid/view/ViewGroup$LayoutParams;)V

    .line 55
    aget-object v6, v2, v8

    invoke-virtual {v3, v6}, Landroid/widget/TableLayout;->addView(Landroid/view/View;)V

    .line 57
    const/4 v0, 0x0

    .local v0, "i":I
    :goto_0
    const/16 v6, 0x8

    if-ge v0, v6, :cond_0

    .line 58
    new-instance v6, Landroid/widget/TableRow;

    invoke-direct {v6, p0}, Landroid/widget/TableRow;-><init>(Landroid/content/Context;)V

    aput-object v6, v2, v0

    .line 59
    aget-object v6, v2, v0

    invoke-virtual {v6, v10}, Landroid/widget/TableRow;->setGravity(I)V

    .line 61
    aget-object v6, v2, v0

    iget-object v7, p0, Lru/nechta/lab3/three;->city:[Ljava/lang/String;

    aget-object v7, v7, v0

    invoke-virtual {p0, v7}, Lru/nechta/lab3/three;->makerow(Ljava/lang/String;)Landroid/widget/TextView;

    move-result-object v7

    invoke-virtual {v6, v7}, Landroid/widget/TableRow;->addView(Landroid/view/View;)V

    .line 62
    invoke-static {}, Ljava/lang/Math;->random()D

    move-result-wide v6

    const-wide/high16 v8, 0x4008000000000000L    # 3.0

    mul-double/2addr v6, v8

    double-to-int v4, v6

    .line 63
    .local v4, "tmp":I
    aget-object v6, v2, v0

    iget-object v7, p0, Lru/nechta/lab3/three;->png:[I

    aget v7, v7, v4

    invoke-virtual {p0, v7}, Lru/nechta/lab3/three;->makepng(I)Landroid/widget/ImageView;

    move-result-object v7

    invoke-virtual {v6, v7}, Landroid/widget/TableRow;->addView(Landroid/view/View;)V

    .line 65
    invoke-static {}, Ljava/lang/Math;->random()D

    move-result-wide v6

    const-wide/high16 v8, 0x4034000000000000L    # 20.0

    mul-double/2addr v6, v8

    double-to-int v6, v6

    add-int/lit8 v5, v6, 0xa

    .line 67
    .local v5, "tmp1":I
    aget-object v6, v2, v0

    new-instance v7, Ljava/lang/StringBuilder;

    invoke-direct {v7}, Ljava/lang/StringBuilder;-><init>()V

    const-string v8, "+"

    invoke-virtual {v7, v8}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    move-result-object v7

    invoke-virtual {v7, v5}, Ljava/lang/StringBuilder;->append(I)Ljava/lang/StringBuilder;

    move-result-object v7

    invoke-virtual {v7}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v7

    invoke-virtual {p0, v7}, Lru/nechta/lab3/three;->makerow(Ljava/lang/String;)Landroid/widget/TextView;

    move-result-object v7

    invoke-virtual {v6, v7}, Landroid/widget/TableRow;->addView(Landroid/view/View;)V

    .line 69
    aget-object v6, v2, v0

    invoke-virtual {v3, v6}, Landroid/widget/TableLayout;->addView(Landroid/view/View;)V

    .line 57
    add-int/lit8 v0, v0, 0x1

    goto :goto_0

    .line 71
    .end local v4    # "tmp":I
    .end local v5    # "tmp1":I
    :cond_0
    invoke-virtual {p0, v3}, Lru/nechta/lab3/three;->setContentView(Landroid/view/View;)V

    .line 73
    return-void
.end method
