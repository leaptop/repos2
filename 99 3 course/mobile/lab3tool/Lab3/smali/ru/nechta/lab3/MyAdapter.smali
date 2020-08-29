.class public Lru/nechta/lab3/MyAdapter;
.super Landroid/widget/ArrayAdapter;
.source "MyAdapter.java"


# annotations
.annotation system Ldalvik/annotation/Signature;
    value = {
        "Landroid/widget/ArrayAdapter",
        "<",
        "Ljava/lang/String;",
        ">;"
    }
.end annotation


# instance fields
.field public cc:Landroid/content/Context;

.field ic:[I

.field val:[Ljava/lang/String;


# direct methods
.method public constructor <init>(Landroid/content/Context;[Ljava/lang/String;[I)V
    .locals 1
    .param p1, "c"    # Landroid/content/Context;
    .param p2, "v"    # [Ljava/lang/String;
    .param p3, "img"    # [I

    .prologue
    .line 15
    const v0, 0x7f030002

    invoke-direct {p0, p1, v0, p2}, Landroid/widget/ArrayAdapter;-><init>(Landroid/content/Context;I[Ljava/lang/Object;)V

    .line 16
    iput-object p1, p0, Lru/nechta/lab3/MyAdapter;->cc:Landroid/content/Context;

    iput-object p2, p0, Lru/nechta/lab3/MyAdapter;->val:[Ljava/lang/String;

    iput-object p3, p0, Lru/nechta/lab3/MyAdapter;->ic:[I

    .line 17
    return-void
.end method


# virtual methods
.method public getView(ILandroid/view/View;Landroid/view/ViewGroup;)Landroid/view/View;
    .locals 6
    .param p1, "pos"    # I
    .param p2, "v"    # Landroid/view/View;
    .param p3, "gr"    # Landroid/view/ViewGroup;

    .prologue
    .line 20
    iget-object v4, p0, Lru/nechta/lab3/MyAdapter;->cc:Landroid/content/Context;

    const-string v5, "layout_inflater"

    invoke-virtual {v4, v5}, Landroid/content/Context;->getSystemService(Ljava/lang/String;)Ljava/lang/Object;

    move-result-object v1

    check-cast v1, Landroid/view/LayoutInflater;

    .line 21
    .local v1, "inflater":Landroid/view/LayoutInflater;
    const v4, 0x7f030002

    const/4 v5, 0x0

    invoke-virtual {v1, v4, p3, v5}, Landroid/view/LayoutInflater;->inflate(ILandroid/view/ViewGroup;Z)Landroid/view/View;

    move-result-object v2

    .line 22
    .local v2, "r":Landroid/view/View;
    const/high16 v4, 0x7f050000

    invoke-virtual {v2, v4}, Landroid/view/View;->findViewById(I)Landroid/view/View;

    move-result-object v3

    check-cast v3, Landroid/widget/TextView;

    .line 23
    .local v3, "textView":Landroid/widget/TextView;
    const v4, 0x7f050001

    invoke-virtual {v2, v4}, Landroid/view/View;->findViewById(I)Landroid/view/View;

    move-result-object v0

    check-cast v0, Landroid/widget/ImageView;

    .line 24
    .local v0, "imageView":Landroid/widget/ImageView;
    iget-object v4, p0, Lru/nechta/lab3/MyAdapter;->val:[Ljava/lang/String;

    aget-object v4, v4, p1

    invoke-virtual {v3, v4}, Landroid/widget/TextView;->setText(Ljava/lang/CharSequence;)V

    .line 25
    iget-object v4, p0, Lru/nechta/lab3/MyAdapter;->ic:[I

    aget v4, v4, p1

    invoke-virtual {v0, v4}, Landroid/widget/ImageView;->setImageResource(I)V

    .line 26
    return-object v2
.end method
